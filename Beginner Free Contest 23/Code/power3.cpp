#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n) {
    int ans = -1;
    int l = 0, r = 1e6;

    while (l <= r) {
        int mid = (l + r) / 2;
        ll tmp = 1LL * mid * mid * mid;

        if (tmp == n) {
            ans = mid;
            break;
        } else if (tmp > n) r = mid - 1;
        else l = mid + 1;
    }

    if (ans != -1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        solve(n);
    }

    return 0;
}