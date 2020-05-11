#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mx = 0, mn = 0, t;
    while (n--) {
        cin >> t;
        mx = max(mx, t);
        mn = min(mn, t);
    }
    cout << (mx - mn) * 2;
    
    return 0;
}