#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, a[maxn];

int l[maxn];
int Kill[maxn];

void dijkstra() {
    for (int i = 1; i <= n; i++) {l[i] = INT_MAX; Kill[i] = 0;}
    l[1] = 0;

    int u, v, mn, t = n;
    while (t--) {
        mn = INT_MAX;
        for (int i = 1; i <= n; i++) 
            if (Kill[i] == 0 && mn > l[i]) { mn = l[i]; u = i; }
        Kill[u] = 1;
        for (int v = 1; v <= n; v++)
            if (Kill[v] == 0) l[v] = min(l[v], min(a[u]%a[v], a[v]%a[u]));
    }
}

int main() 
{
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dijkstra();

    int res = 0;
    for (int i = 1; i <= n; i++) res += l[i];

    cout << res;

    return 0;
}