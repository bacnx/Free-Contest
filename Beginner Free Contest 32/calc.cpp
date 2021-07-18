#include <bits/stdc++.h>
using namespace std;

void solve() {
	int mx = 0, s = 0;
	for (int i = 0; i < 3; i++) {
		int a; cin >> a;
		s += a;
		mx = max(mx, a);
	}

	if (s - mx == mx) cout << "yes\n";
	else cout << "no\n";
}

int main() {
	solve();
	solve();

	return 0;
}