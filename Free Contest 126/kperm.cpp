#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;

	int cur = (k + 2) / 2;
	if (k % 2 == 0) {
		for (int i = 1; i <= k; i++) {
			cout << cur << ' ';
			if (i % 2 == 0) cur += i;
			else cur -= i;
		}
	} else {
		for (int i = 1; i <= k; i++) {
			cout << cur << ' ';
			if (i % 2 == 0) cur -= i;
			else cur += i;
		}
	}

	for (int i = k + 1; i <= n; i++) {
		cout << i << ' ';
	}

	return 0;
}