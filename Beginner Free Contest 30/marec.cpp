#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[1003];

int main() {
	cin >> n;
	int aMax = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		cnt[a]++;
		aMax = max(aMax, a);
	}

	int res = 0;
	for (int i = 1; i <= aMax; i++) {
		if (cnt[i] < 2) continue;
		if (cnt[i] >= 4) res++;
		for (int j = i + 1; j <= aMax; j++) {
			if (cnt[j] >= 2) res++;
		}
	}
	cout << res;

	return 0;
}