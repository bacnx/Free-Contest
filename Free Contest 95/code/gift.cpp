#include <bits/stdc++.h>
using namespace std;

int n, a[1000000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = 0, r = 0, ans = 1;
    for (r = 1; r < n; r++) {
        if (a[r] <= a[r-1]) l = r;
        ans = max(ans, r-l+1);
    }

    cout << ans;

    return 0;
}
