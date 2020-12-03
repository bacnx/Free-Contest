#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}

#define ll long long
const int MAX = 1e6 + 6;

int n, X;
ll s[MAX];
int cnt[MAX], ok[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    read(n); read(X);
    for (int i = 1; i <= n; i++) 
        read(s[i]), s[i] += s[i - 1];

    ll res = 0;
    int lim = min(n, X);
    for (int k = 1; k <= lim; k++) if (X % k == 0) {
        int xx = X / k;
        for (int i = k; i <= n; i++) if (xx >= s[i] - s[i - k]) {
            cnt[s[i] - s[i - k]]++;
            ok[i] = 1;
        }
        for (int i = k; i <= n; i++) if (ok[i])
            res += cnt[xx - (s[i] - s[i - k])];
        for (int i = k; i <= n; i++) if (ok[i]) {
            cnt[s[i] - s[i - k]] = 0;
            ok[i] = 0;
        }
    }
    cout << res;

    return 0;
}