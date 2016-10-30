#include <iostream>
#include <algorithm>
using namespace std;
struct P {
	int v, id;
	bool operator < (const P &rhs) {
		return v < rhs.v;
	}
}p[1001];
int ans[1001], al = 0;
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].v;
		p[i].id = i + 1;
	}
	sort(p, p + n);
	p[n].v = 1000000;
	for (int i = 0; i < n; i++)if (p[i].v <=i+1 && i+2 < p[i + 1].v)ans[al++] = i;
	cout << al << endl;
	for (int i = 0; i < al; i++) {
		cout << ans[i] + 1;
		for (int j = 0; j <= ans[i]; j++)cout << " " << p[j].id;
		cout << endl;
	}
	return 0;
}
