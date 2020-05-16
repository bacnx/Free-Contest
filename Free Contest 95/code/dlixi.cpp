#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for (int i = max(a, 0); i <= b; i++)
        if (i % c == 0) ans++;

    cout << ans;

    return 0;
}
