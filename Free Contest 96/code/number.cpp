#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  vector<int> a(100, 0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a[temp%k]++;
  }

  int res = n;
  for (int i = 1; i <= (k-1)/2; i++) {
    res -= min(a[i], a[k-i]);
  }
  res = res - a[0] + min(a[0], 1);
  if (k%2 == 0) {
    res = res - a[k/2] + min(a[k/2], 1);
  }
  cout << res;

  return 0;
}