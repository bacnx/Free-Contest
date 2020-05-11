#include <bits/stdc++.h>
using namespace std;

#define NO { cout << "NO"; return 0; }
const int maxn = 1e5+1;

long long n, a[maxn];

int main() 
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    
    for (long long i = 1; i <= n; i++)
        for (long long j = i; j <= n/i; j++)
            if (a[i] * a[j] != a[i*j]) NO
    cout << "YES";
    
    return 0;
}