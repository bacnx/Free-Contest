#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 500005;

string s;
int n, a[maxn];

void init() {
    for (int i = 0; i <= n; i++) a[i] = 0;
}

void create(int x) {
    a[x] = 0; 
    a[x-1] = max(a[x-1], (long long)1); 
    a[x+1] = max(a[x+1], (long long)1);
    int i = x-2;
    while (i >= 0 && s[i] == s[i+1]) { a[i] = max(a[i], a[i+1] + 1); i--; }
    i = x+1;
    while (i < n && s[i] == s[i-1]) { a[i+1] = max(a[i+1], a[i] + 1); i++; }
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);

    cin >> s;
    n = (int)s.size();

    init();
    if (s[0] == '<') create(0);
    if (s[n-1] == '>') create(n);
    for (int i = 1; i < n; i++)
        if (s[i-1] == '>' && s[i] == '<') create(i);

    int psum = 0;
    for (int i = 0; i <= n; i++) psum += a[i];

    cout << psum;

    return 0;
}