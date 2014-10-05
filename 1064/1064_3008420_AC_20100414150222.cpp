#include <stdio.h>

#define MAXN 10000

int A[MAXN], ans[MAXN + 1];
int N, L1, i;
int i2, l, cnt, tmp;

int BinarySearch(int x)
{
int p, q, i, L;

p = 0; /* Left border of the search */
q = N-1; /* Right border of the search */
L = 0; /* Comparison counter */

while (p <= q)
{
i = (p + q) / 2;
++L;
if (A[i] == x)
{
// printf("Found item i = %d in L = %d comparisons", i, L);
return L;
}
if (x < A[i])
q = i - 1;
else
p = i + 1;
}

return 0;
}


int main()
{
scanf("%d %d", &i, &L1);

for (i2 = 0; i2 <= MAXN; i2++)
{
A[i2] = i2;
N = i2;
if (BinarySearch(i) == L1)
{
ans[i2] = 1;
}
}



cnt = 0;
tmp = 0;
for (i2 = 0; i2 <= MAXN; i2++)
{
if (ans[i2] == 0) tmp = 0;
else 
{
if (tmp == 0) cnt++;
tmp = 1;
}
}
printf("%d\n", cnt); 

tmp = 0;
l = -1; 
for (i2 = 0; i2 <= MAXN; i2++)
{

if (ans[i2] == 0)
{
if (l != -1) printf("%d %d\n", l, i2-1); 
l = -1;
tmp = 0;
}
else 
{
if (tmp == 0) l = i2;
tmp = 1;
}
}

if (l != -1) printf("%d %d", l, MAXN);

return 0;
} 