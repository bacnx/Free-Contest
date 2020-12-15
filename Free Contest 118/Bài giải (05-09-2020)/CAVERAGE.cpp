#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define sort(vec) sort((vec).begin(),(vec).end())
typedef long long ll;

ll dp[51][5010];

int main() {
  int n, a;
  cin >> n >> a;
  vector<int> x(n);
  rep(i, n) {
    cin >> x[i];
    x[i] -= a;
  }
  dp[0][2500] = 1;
  rep(i, n)
    rep(j, 5010) {
      dp[i + 1][j + x[i]] += dp[i][j];
      dp[i + 1][j] += dp[i][j];
    }
  cout << dp[n][2500] - 1 << endl;
}
