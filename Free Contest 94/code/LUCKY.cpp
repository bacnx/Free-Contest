#include <bits/stdc++.h>
using namespace std;

const int maxn = 300001;

int n;
long long psum[maxn], a[maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    psum[n+1] = 0;
    for (int i = n; i > 0; i--)
        psum[i] = psum[i+1] + a[i];
    
    long long res = 0;
    for (int i = 1; i < n; i++)
        res += a[i] * psum[i+1];
    
    cout << res;

    return 0;
}