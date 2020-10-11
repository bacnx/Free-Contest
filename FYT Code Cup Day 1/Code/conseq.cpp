#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6+1;
const int MOD = 1e9+7;

vector<int> id[maxN], val[maxN];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a <= n) id[a].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < (int)id[1].size(); i++) {
        val[1].push_back(1);
        ans++;
    }
    for (int i = 2; i <= n; i++) {
        if (id[i].empty()) break;
        int vt = -1, t = 0;
        for (int j = 0; j < (int)id[i].size(); j++) {
            while (vt != id[i-1].size()-1 && id[i-1][vt+1] < id[i][j]) {
                vt++;
                t = (t + val[i-1][vt]) % MOD;
            }
            val[i].push_back(t);
            ans = (ans + t) % MOD;
        }
    }
    cout << ans;

    return 0;
}