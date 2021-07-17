#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	if (n % 4 == 0) {
		cout << '0';
	}
	else if (n % 2 == 0) {
		cout << '1';
	}
	else {
		cout << '2';
	}

	return 0;
}