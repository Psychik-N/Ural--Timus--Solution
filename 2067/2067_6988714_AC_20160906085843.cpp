#include <iostream>
#include <algorithm>
using namespace std;
struct P {
	int x, y, id;
	bool operator < (const P& rhs) {
		return x < rhs.x || (x == rhs.x&&y < rhs.y);
	}
}p[200001];
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i + 1;
	}
	sort(p, p + n);
	if (p[0].x == p[1].x) {
		for (int i = 2; i < n; i++)if (p[i].x != p[0].x) {
			cout << 0 << endl;
			return 0;
		}
		cout << 1 << endl << p[0].id << " " << p[n - 1].id;
	}
	else if (p[0].y == p[1].y) {
		for (int i = 2; i < n; i++)if (p[i].y != p[0].y) {
			cout << 0 << endl;
			return 0;
		}
		cout << 1 << endl << p[0].id << " " << p[n - 1].id;
	}
	else {
		for (int i = 2; i < n; i++)if ((long long)(p[i].x - p[0].x)*(p[i].y - p[1].y) != (long long)(p[i].x - p[1].x)*(p[i].y - p[0].y)) {
			cout << 0 << endl;
			return 0;
		}
		cout << 1 << endl << p[0].id << " " << p[n - 1].id;
	}
	return 0;
}
