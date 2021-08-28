#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int res = 0;
        while (n--) {
            int x, y; cin >> x >> y;
            res = max(res, x + y);
        }
        cout << res << '\n';
    }

    return 0;
}