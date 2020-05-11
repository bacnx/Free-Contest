#include <bits/stdc++.h>
using namespace std;

int case1(int n, int a, int b, int c) { return max(0, a + b + c - 2*n); }
int case2(int n, int a, int b, int c) { return min(a, min(b, c)); }

int main()
{
    int r, t, n, a, b, c;
    cin >> r;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c;
        if (r == 1) cout << case1(n, a, b, c) << endl;
        else cout << case2(n, a, b, c) << endl;
    }

    return 0;
}