#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int64_t n, x, y; cin >> n >> x >> y;

    int ans = 0;
    while (x != y) {
        if (x > y) x = x >> 1;
        else y = y >> 1;
        ans++;
    }
    cout << ans;

    return 0;
}