#include <bits/stdc++.h>
using namespace std;

int n, a[1003];
int cnt[1003], mark[1003];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mark[j] = 0;
			cnt[j] = 0;
		}
		for (int j = 1; j <= n; j++) {
			if (j - i > 0) mark[a[j-i]]--;
			int tmp = j;
			if (tmp > n / 2) tmp = n - tmp + 1;
			if (mark[a[j]] == 0) {
				mark[a[j]]++;
				cnt[a[j]] += tmp;
			}
		}

		bool done = false;
		for (int j = 1; j <= n; j++) if (cnt[j] >= n - i + 1) {
			cout << j << ' ';
			done = true;
			break;
		}
		if (!done) cout << "-1 ";
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();

	return 0;
}