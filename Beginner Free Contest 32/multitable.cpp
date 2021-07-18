#include <bits/stdc++.h>
using namespace std;

int n, a[50][50];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> a[i][j];
	}

	for (int i = 0; i < n; i++) {
		cout << sqrt(a[i][i]) << ' ';
	}

	return 0;
}