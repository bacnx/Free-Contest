#include <bits/stdc++.h>
using namespace std;

void solveMin() {
	int t; cin >> t;
	int a[4];
	while (t--) {
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		sort(a, a + 4, greater<int>());
		cout << max(0, a[2] + a[3] - a[0]) << '\n';
	}
}

void solveMax() {
	int t; cin >> t;
	int a[4];
	while (t--) {
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		sort(a, a + 4, greater<int>());
		cout << a[3] << '\n';
	}
}

int main() {
	int r; cin >> r;
	if (r == 1) solveMin();
	else solveMax();

	return 0;
}