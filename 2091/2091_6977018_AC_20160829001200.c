#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int v[101][101];
int main() {
	int n, m, i, j, k, bv = 200000000, bi, bj, c1, c2, c3, c4;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)for (j = 1; j <= m; j++)scanf("%d", &v[i][j]);
	for (i = 1; i <= m; i++)for (j = i + 1; j <= m; j++) {
		c1 = c2 = c3 = c4 = 0;
		for (k = 1; k <= n; k++) {
			if (v[k][i] && v[k][j])c1++;
			else if (v[k][i])c2++;
			else if (v[k][j])c3++;
			else c4++;
		}
		if (c2 > c1)c1 = c2;
		if (c3 > c1)c1 = c3;
		if (c4 > c1)c1 = c4;
		if (c1 < bv) {
			bv = c1;
			bi = i;
			bj = j;
		}
	}
	printf("%d\n%d %d\n", bv, bi, bj);
	return 0;
}
