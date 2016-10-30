#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int b, c, d, k, p;
	double a1, a2;
	scanf("%d%d%d%d%d", &b, &c, &d, &k, &p);
	a1 = c*k + (double)k*(k + 1) / 2 * d;
	a2 = a1*(1 + p / 100.0);
	a1 += b;
	if (a1 + 1e-8 < a2)printf("Cash\n%.8lf\n", a2 - a1);
	else printf("Insurance\n%.8lf\n", a1 - a2);
	return 0;
}
