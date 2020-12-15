#include<bits/stdc++.h>
using namespace std;

#define MASK(i) (1LL << (i))
#define BIT(i, x) (((x) >> (i)) & 1)

int n, A;
int a[55];
int f[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> A;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int mask = 1, nMask = MASK(n) - 1; mask <= nMask; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) if (BIT(i, mask))
            sum += a[i];
        if (sum == A * __builtin_popcount(mask)) ans++;
    }
    cout << ans;

    return 0;
}