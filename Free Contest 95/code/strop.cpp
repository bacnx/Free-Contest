#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;

int n, m, q, diffS[maxn], diffT[maxn];
string s, t;

void init_diff() {
    diffS[0] = 0;
    for (int i = 1; i <= n; i++)
        if (s[i-1] == 'A') diffS[i] = diffS[i-1] - 1;
        else diffS[i] = diffS[i-1] + 1;
    diffT[0] = 0;
    for (int i = 1; i <= m; i++)
        if (t[i-1] == 'A') diffT[i] = diffT[i-1] - 1;
        else diffT[i] = diffT[i-1] +1;
}

int get_diff(char c, int l, int r) {
    if (c == 's') return diffS[r] - diffS[l-1];
    else return diffT[r] - diffT[l-1];
}

int main()
{
    cin >> s >> t;
    n = s.size(), m = t.size();
    init_diff();

    cin >> q;
    int a, b, c, d;
    while(q--) {
        cin >> a >> b >> c >> d;
        if ((get_diff('s', a, b)%3 + 3)%3 == (get_diff('t', c, d)%3 + 3)%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
