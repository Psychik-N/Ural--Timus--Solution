#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str[4010];
int lc[4010], lmb[4010];
int f[4010] = { 1 }, m[4010] = { -1 };
void go(int p) {
	if (p == -1)return;
	go(m[p]);
	int i;
	for (i = m[p] + 1; i <= p; i++)putchar(str[i]);
	putchar(' ');
}
int main() {
	int i, l, j, k, tv;
	scanf("%s", str);
	l = strlen(str);
	for (i = 0; i < l; i++) {
		j = k = i;
		lc[i] = 1;
		while (j > 0 && k < l - 1 && str[j - 1] == str[k + 1]) {
			j--;
			k++;
			lc[i] += 2;
		}
		j = i - 1;
		k = i;
		lmb[i] = 0;
		while (j >= 0 && k < l&&str[j] == str[k]) {
			j--;
			k++;
			lmb[i] += 2;
		}
	}
	for (i = 1; i < l; i++) {
		f[i] = 200000000;
		for (j = 0; j < i; j++) {
			if (((i - j) % 2 == 1 && lc[(i + j + 1) / 2] >= i-j) || ((i - j) % 2 == 0 && lmb[(i + j) / 2 + 1] >= i-j)) {
				tv = f[j] + 1;
				if (tv < f[i]) {
					f[i] = tv;
					m[i] = j;
				}
			}
		}
		if ((i % 2 == 1 && lmb[(i + 1) / 2] >= i + 1) || (i % 2 == 0 && lc[i / 2] >= i + 1)) {
			tv = 1;
			if (tv < f[i]) {
				f[i] = tv;
				m[i] = -1;
			}
		}
	}
	printf("%d\n", f[l - 1]);
	go(l - 1);
}
