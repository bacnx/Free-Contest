#include <bits/stdc++.h>
using namespace std;

int n, a[100000];

int main() {
  cin >> n;
  int maxA = 0, temp;
  while (n--) {
    cin >> temp;
    a[temp]++;
    maxA = max(maxA, temp);
  }

  for (int i = maxA; i >= (maxA+2)/2; i--) {
    if (a[i] < 2) {
      cout << "Impossible";
      return 0;
    }
  }
  if (maxA % 2 == 0 && a[maxA/2] < 1) {
    cout << "Impossible";
    return 0;
  }
  cout << "Possible";

  return 0;
}