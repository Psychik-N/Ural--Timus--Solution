#include <stdio.h>
int v[101][101];
int main() {
	int n, i, j, bv = 0, ob = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)for (j = 0; j < n; j++)scanf("%d", &v[i][j]);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)ob += v[i][j];
		for (j = 0; j < i; j++)ob -= v[j][i];
		if (ob > bv)bv = ob;
	}
	ob = 0;
	for (i = n-1; i >= 0; i--) {
		for (j = i + 1; j < n; j++)ob -= v[j][i];
		for (j = 0; j < i; j++)ob += v[i][j];
		if (ob > bv)bv = ob;
	}
	printf("%d\n", bv);
	return 0;
}
