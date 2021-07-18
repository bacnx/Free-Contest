#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int m, n, a[1003][1003];

int countAdj(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		ans += a[x + dx[i]][y + dy[i]];
	}
	return ans;
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		char c; cin >> c;
		if (c == '#') {
			a[i][j] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		if (a[i][j]) ans += countAdj(i, j);
	}
	ans /= 2;

	int mx = 0;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		if (!a[i][j]) mx = max(mx, countAdj(i, j));
	}

	cout << ans + mx;

	return 0;
}