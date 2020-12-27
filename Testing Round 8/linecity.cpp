#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int l, n;
int a[MAX];

int main() {
    cin >> l >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, (a[i+1] - a[i]) / 2);
    
    ans = max(ans, a[1] - 0);
    ans = max(ans, l - a[n]);

    cout << ans;

    return 0;
}