#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
const int MAX = 1e5+5;

struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick();
    Fenwick(int _n) {
        n = _n;
        f.resize(n + 1, 0);
    }

    void set(int i, int x) {
        for (; i <= n; i += (i & -i)) f[i] += x;
    }
    ll get(int i) {
        ll res = 0;
        for (; i >= 1; i -= (i & -i)) res += f[i];
        return res;
    }
};

int n;
pii a[MAX], b[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) b[i] = pii(a[i].second, i);
    sort(b + 1, b + n + 1);

    ll res = 0;
    Fenwick f(n);
    for (int i = n; i >= 1; i--) {
        res += f.get(b[i].second - 1);
        f.set(b[i].second, 1);
    }
    cout << res;

    // int res = 0;
    // for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++)
    //     res += a[i].second < a[j].second;
    // cout << res;

    return 0;
}