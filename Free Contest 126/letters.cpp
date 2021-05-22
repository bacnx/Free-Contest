#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	char ca, cb;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (i == 0) ca = c;
		if (i == n - 1) cb = c;
	}

	int a, b;
	if (ca == 'a' || ca == '?') a = 1;
	else a = 0;
	if (cb == 'b' || cb == '?') b = 0;
	else b = 1;

	cout << a - b;

	return 0;
}