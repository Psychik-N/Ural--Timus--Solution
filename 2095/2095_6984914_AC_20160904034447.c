#include <stdio.h>
typedef long long i64;
i64 go(i64 v) {
	int t = 2;
	while (v>0 && v >= t) {
		v -= v / t;
		t++;
	}
	return v;
}
int main() {
	i64 l, r;
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", go(r) - go(l - 1));
	return 0;
}
