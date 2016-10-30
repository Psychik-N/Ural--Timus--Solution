package problems.mulknap.timus;

//import problems.mulknap.ExactMulknapSolver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * This is a partial implementation of Pisinger's MULKNAP that solves T1394.
 *
 * @author David Pisinger
 * @author Maxim Buzdalov
 */
public class MulKnap{
    static void insertionSort(int[] array, int[] aux, int from, int to) {
        for (int i = from + 1; i < to; ++i) {
            int j = i;
            while (j > from && array[j] < array[j - 1]) {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                tmp = aux[j];
                aux[j] = aux[j - 1];
                aux[j - 1] = tmp;
                --j;
            }
        }
    }

    private static int[][] s = new int[100][300];
    private static int[][] b = new int[100][300];

    private static int[] temp1 = new int[256];
    private static boolean[] temp2 = new boolean[256];
    private static int[] temp3 = new int[10000];

    private static int[][] getS(int fw, int sw) {
        if (s.length < fw || s[0].length < sw) {
            s = new int[Math.max(s.length, fw)][Math.max(s[0].length, sw)];
        }
        return s;
    }

    private static int[][] getB(int fw, int sw) {
        if (b.length < fw || b[0].length < sw) {
            b = new int[fw][sw];
        }
        return b;
    }

    /*
     * This method assumes that all items are positive, sum is non-negative,
     * no item exceeds sum, and sum of all items exceed sum.
     */
    private static int subsetSumFiltered(int n, int[] items, int sum, boolean[] answer) {
        int r = 0;
        for (int i : items) {
            r = Math.max(r, i);
        }
        int minWeight = Math.max(0, sum - r + 1);
        int maxWeight = sum + r;
        int breakItem = 0;
        int breakWeight = 0;
        for (int i = 0; i < n; ++i) {
            if (breakWeight + items[i] > sum) {
                breakItem = i;
                break;
            } else {
                breakWeight += items[i];
            }
        }

        int firstWidth = n - breakItem + 1;
        int secondWidth = maxWeight - minWeight + 1;

        //the first index is actually in the range [breakItem - 1 .. n - 1]
        int[][] s = getS(firstWidth, secondWidth); //new int[firstWidth][secondWidth];
        int[][] b = getB(firstWidth, secondWidth); //new int[firstWidth][secondWidth];
        Arrays.fill(s[0], 0, sum - minWeight + 1, -1);
        Arrays.fill(s[0], sum - minWeight + 1, secondWidth, 0);
        s[0][breakWeight - minWeight] = breakItem;

        final int COMMAND_DEC_T = 1;
        final int COMMAND_TAKE_T = 2;
        final int COMMAND_TAKE_S = 3;

        Arrays.fill(b[0], -1);

        for (int t = 1; t < firstWidth; ++t) {
            int[] prevS = s[t - 1];
            int[] currS = s[t];
            int[] currB = b[t];
            System.arraycopy(prevS, 0, currS, 0, secondWidth);
            Arrays.fill(currB, 0, secondWidth, COMMAND_DEC_T);

            for (int w = sum - minWeight; w >= 0; --w) {
                int w$ = w + items[t + breakItem - 1];
                if (currS[w$] < currS[w]) {
                    currS[w$] = currS[w];
                    currB[w$] = COMMAND_TAKE_T;
                }
            }
            for (int w = sum + items[t + breakItem - 1] - minWeight; w > sum - minWeight; --w) {
                for (int j = currS[w] - 1; j >= prevS[w]; --j) {
                    int w$ = w - items[j];
                    if (currS[w$] < j) {
                        currS[w$] = j;
                        currB[w$] = COMMAND_TAKE_S;
                    }
                }
            }
        }

        //answer restoring
        for (int w = sum; w >= 0; --w) {
            int ss = s[firstWidth - 1][w - minWeight];
            if (ss != -1) {
                int curw = w - minWeight;
                Arrays.fill(answer, breakItem, n, false);
                Arrays.fill(answer, 0, breakItem, true);
                int tt = firstWidth - 1;
                while (tt > 0) {
                    switch (b[tt][curw]) {
                        case COMMAND_DEC_T:
                            --tt;
                            break;
                        case COMMAND_TAKE_T:
                            curw -= items[tt + breakItem - 1];
                            answer[tt + breakItem - 1] = true;
                            --tt;
                            break;
                        case COMMAND_TAKE_S:
                            ss = s[tt][curw];
                            curw += items[ss];
                            answer[ss] = false;
                            break;
                        default:
                            throw new AssertionError("Answer restoring failed");
                    }
                }
                return w;
            }
        }
        throw new AssertionError("Restoring failed, weight not found");
    }

    public static int subsetSumCount = 0;
    public static int subsetSumSize = 0;
    public static int[] sizeCounts = new int[100];

    /**
     * The interface for subset sub solver.
     * It checks the preconditions, copes with degeracies and checks the postconditions.
     * @param n the number of items actually stored.
     * @param items the array of items.
     * @param sum the maximum sum.
     * @param answer the destination array for an answer. <code>answer[i]</code> will be set for <tt>true</tt>
     * if the ith item is to be taken.
     * @return returns the gathered sum.
     */
    public static int subsetSum(int n, int[] items, int sum, boolean[] answer) {
        ++subsetSumCount;
        subsetSumSize += n;
        sizeCounts[n]++;

        if (n <= 8) {
            int half = n / 2;
            temp1[0] = 0;
            for (int i = 1; i < 1 << half; ++i) {
                int j = i & (i - 1);
                temp1[i] = temp1[j] + items[Integer.numberOfTrailingZeros(i ^ j)];
                temp3[temp1[i]] = i;
            }

            for (int i = 0; i < 1 << half; ++i) {
                temp3[temp1[i]] = 0;
            }
        }

        int itemSum = 0;
        int itemMax = 0;
        for (int i1 = 0; i1 < n; i1++) {
            int i = items[i1];
            itemSum += i;
            itemMax = Math.max(itemMax, i);
        }
        if (itemSum <= sum) {
            Arrays.fill(answer, true);
        } else if (itemMax > sum) {
            int size = 0;
            int nsum = 0;
            for (int i1 = 0; i1 < n; i1++) {
                int i = items[i1];
                if (i <= sum) {
                    ++size;
                    nsum += i;
                }
            }
            if (nsum <= sum) {
                for (int i = 0; i < n; ++i) {
                    answer[i] = items[i] <= sum;
                }
            } else {
                int[] newItems = temp1;
                boolean[] newAns = temp2;
                int count = 0;
                for (int i = 0, j = 0; i < n; ++i) {
                    if (items[i] <= sum) {
                        newItems[j++] = items[i];
                        ++count;
                    }
                }
                subsetSumFiltered(count, newItems, sum, newAns);
                for (int i = 0, j = 0; i < n; ++i) {
                    answer[i] = items[i] <= sum && newAns[j++];
                }
            }
        } else {
            subsetSumFiltered(n, items, sum, answer);
        }
        int selectedSum = 0;
        for (int i = 0; i < n; ++i) {
            if (answer[i]) {
                selectedSum += items[i];
            }
        }
        return selectedSum;
    }

    @Override
    public long solve(int[] items, int[] sacks, int[] answer) {
        return mulknap(items.clone(), sacks.clone(), answer);
    }

    private static class Context {
        final int[] items;
        final int[] optimal;
        final int[] current;
        final int[] dLimits;
        final int[] itemPerm;
        
        int optimalWeight;
        int sumOfAllWeights;
        final int itemCount;
        final int sackCount;

        final int[] tempI;
        final int[] tempS;
        final boolean[] tempIB;
        final boolean[] tempIB2;

        long opCount;

        public Context(int[] items, int sackCount) {
            this.items = items.clone();
            this.itemCount = items.length;
            this.sackCount = sackCount;
            optimal = new int[itemCount];
            current = new int[itemCount];
            Arrays.fill(optimal, -1);
            Arrays.fill(current, -1);
            dLimits = new int[itemCount];
            optimalWeight = 0;

            for (int item : items) {
                sumOfAllWeights += item;
            }

            itemPerm = new int[itemCount];
            for (int i = 0; i < itemCount; ++i) {
                itemPerm[i] = i;
            }

            tempI = new int[itemCount];
            tempS = new int[sackCount];
            tempIB = new boolean[itemCount];
            tempIB2 = new boolean[itemCount];
        }

        void swap(int i, int j) {
            int tmp;
            tmp = items[i]; items[i] = items[j]; items[j] = tmp;
            tmp = optimal[i]; optimal[i] = optimal[j]; optimal[j] = tmp;
            tmp = current[i]; current[i] = current[j]; current[j] = tmp;
            tmp = dLimits[i]; dLimits[i] = dLimits[j]; dLimits[j] = tmp;
            tmp = itemPerm[i]; itemPerm[i] = itemPerm[j]; itemPerm[j] = tmp;
        }

        public void solve(int h, int w, int[] sacks) {
            ++opCount;
            int minNonZero = 0;
            while (minNonZero < sacks.length && sacks[minNonZero] == 0) {
                ++minNonZero;
            }
            if (minNonZero == sacks.length) {
                return;
            }
            //Tightening the constraints
            for (int sack = minNonZero; sack < sackCount; ++sack) {
                int cnt = 0;
                for (int item = h; item < itemCount; ++item) {
                    if (dLimits[item] <= sack) {
                        tempI[cnt++] = items[item];
                    }
                }
                opCount += cnt;
                //sacks[sack] = subsetSum(cnt, tempI, sacks[sack], tempIB);
                //TODO: cheat #1
                if (sacks[sack] != subsetSum(cnt, tempI, sacks[sack], tempIB)) {
                    return;
                }
                //TODO: cheat ends
            }
            while (minNonZero < sacks.length && sacks[minNonZero] == 0) {
                ++minNonZero;
            }
            if (minNonZero == sacks.length) {
                return;
            }
            int sumCap = 0;
            for (int sack : sacks) {
                sumCap += sack;
            }
            int surrogateUpperBound = sumCap;
            opCount += itemCount - h;
            if (w + surrogateUpperBound > optimalWeight) {
                //tempIB is used in the heuristic constructor
                System.arraycopy(sacks, 0, tempS, 0, sackCount);
                //tempS is used to store decreasing capacities. 
                //Constructing a heuristic solution by distributing
                for (int sack = minNonZero; sack < sackCount; ++sack) {
                    int cnt = 0;
                    for (int item = h; item < itemCount; ++item) {
                        if (current[item] == -1) {
                            tempI[cnt++] = items[item];
                        }
                    }
                    Arrays.fill(tempIB2, false);
                    tempS[sack] -= subsetSum(cnt, tempI, sacks[sack], tempIB2);
                    opCount += cnt;
                    cnt = 0;
                    for (int item = h; item < itemCount; ++item) {
                        if (current[item] == -1) {
                            if (tempIB2[cnt++]) {
                                current[item] = sack;
                            }
                        }
                    }
                }
                //Pushing some items which still fit
                for (int item = h; item < itemCount; ++item) {
                    if (current[item] == -1) {
                        for (int sack = minNonZero; sack < sackCount; ++sack) {
                            if (tempS[sack] >= items[item]) {
                                current[item] = sack;
                                tempS[sack] -= items[item];
                                break;
                            }
                        }
                    }
                }
                int currentSum = w;
                for (int item = h; item < itemCount; ++item) {
                    if (current[item] != -1) {
                        currentSum += items[item];
                    }
                }
                if (currentSum > optimalWeight) {
                    System.out.println(optimalWeight + " -> " + currentSum);
                    optimalWeight = currentSum;
                    System.arraycopy(current, 0, optimal, 0, itemCount);
                }
                Arrays.fill(current, h, itemCount, -1);
            }
            if (w + surrogateUpperBound > optimalWeight) {
                int minItem = -1;
                for (int item = h; item < itemCount; ++item) {
                    if (dLimits[item] <= minNonZero) {
                        if (minItem == -1 || items[minItem] > items[item]) {
                            minItem = item;
                        }
                    }
                }

                swap(minItem, h);

                if (items[h] <= sacks[minNonZero]) {
                    current[h] = minNonZero;
                    int[] newSacks = sacks.clone();
                    newSacks[minNonZero] -= items[h];
                    solve(h + 1, w + items[h], newSacks);
                    current[h] = -1;
                }
                int oldD = dLimits[h];
                dLimits[h] = minNonZero + 1;
                solve(h, w, sacks);
                dLimits[h] = oldD;
                swap(minItem, h);
            }
        }
    }

    /**
     * Solves an exact mulknap problem.
     *
     * The answer is returned in answer array: answer[i] is the index of a knapsack
     * where to place the ith item (-1 if there is no knapsack where to place it; obviously,
     * in the solved Timus problem this is not the case).
     *
     * @param items the items.
     * @param sacks the knapsack capacities.
     * @param answer the place where to write an answer.
     * @return the approximate number of operations.
     */
    public static long mulknap(int[] items, int[] sacks, int[] answer) {
        //TODO: cheat #2
        int[] itemFPerm = new int[items.length];
        for (int i = 0; i < items.length; ++i) {
            itemFPerm[i] = i;
        }
        insertionSort(items, itemFPerm, 0, items.length);
        for (int i = 0, j = items.length - 1; i < j; ++i, --j) {
            int tmp = items[i]; items[i] = items[j]; items[j] = tmp;
            tmp = itemFPerm[i]; itemFPerm[i] = itemFPerm[j]; itemFPerm[j] = tmp;
        }
        //TODO: cheat ends
        int sackCount = sacks.length;
        int[] sackFPerm = new int[sackCount];
        for (int i = 0; i < sackCount; ++i) {
            sackFPerm[i] = i;
        }
        insertionSort(sacks, sackFPerm, 0, sacks.length);
        Context context = new Context(items, sackCount);
        context.solve(0, 0, sacks.clone());
        for (int i = 0; i < items.length; ++i) {
            answer[context.itemPerm[itemFPerm[i]]] = context.optimal[i];
        }
        for (int i = 0; i < items.length; ++i) {
            if (answer[i] != -1) {
                answer[i] = sackFPerm[answer[i]];
            } else {
                throw new AssertionError();
            }
        }
        return context.opCount;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer nm = new StringTokenizer(in.readLine());
        int itemCount = Integer.parseInt(nm.nextToken());
        int sackCount = Integer.parseInt(nm.nextToken());
        int[] items = new int[itemCount];
        for (int i = 0; i < itemCount; ++i) {
            items[i] = Integer.parseInt(in.readLine().trim());
        }
        int[] sacks = new int[sackCount];
        for (int i = 0; i < sackCount; ++i) {
            sacks[i] = Integer.parseInt(in.readLine().trim());
        }
        in.close();
        int[] answer = new int[itemCount];

        mulknap(items.clone(), sacks, answer);

        for (int sack = 0; sack < sackCount; ++sack) {
            int cnt = 0;
            for (int i : answer) {
                if (i == sack) {
                    ++cnt;
                }
            }
            System.out.println(cnt);
            for (int i = 0; i < itemCount; ++i) {
                if (answer[i] == sack) {
                    System.out.print(items[i] + " ");
                }
            }
            System.out.println();
        }
    }
}
