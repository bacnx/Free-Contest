#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    if (n < 2 || a > b) cout << 0;
    else cout << (b-a)*(n-1) + a-b + 1;

    return 0;
}