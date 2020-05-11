#include <bits/stdc++.h>
using namespace std;

string s;
int n, m, a[100005];

int main()
{
    cin >> s; n = (int)s.size();
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    a[m+1] = n/2 + 1;

    sort(a+1, a+m+1);

    for (int i = 1; i <= m; i+=2)
        for (int j = a[i]; j < a[i+1]; j++)
            swap(s[j-1], s[n-j]);
    
    cout << s;

    return 0;
}