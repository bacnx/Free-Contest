#include <bits/stdc++.h>
using namespace std;

int n, a[100005];
int dp[100005];

int sub1() {
	int ans = 0, mx = -10000;
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 0) {
			ans += a[i];
			ok = true;
		}
		mx = max(mx, a[i]);
	}
	return ok ? ans : mx;
}

int sub2() {
	int ans = -10000;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(a[i], dp[i-1] + a[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << sub1() << ' ' << sub2() << '\n';
}

int main() {
	int t; cin >> t;
	while (t--) solve();

	return 0;
}