#include <bits/stdc++.h>
using namespace std;

int n, a[200005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long s = a[n];
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] >= a[i + 1]) {
			a[i] = a[i + 1] - 1;
		}
		s += a[i];
		if (a[i] == 0) break;
	}

	cout << s;

	return 0;
}