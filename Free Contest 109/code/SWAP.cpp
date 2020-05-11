#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 100005;

int n, q, a[maxn];

int ST[maxn*4];

void update(int id, int l, int r, int i, int u)  {
    if (i < l || i > r) return ;
    if (l == r) { ST[id] = u; return ; }

    int mid = (l + r) / 2;
    update(id*2, l, mid, i, u);
    update(id*2+1, mid+1, r, i, u);

    ST[id] = ST[id*2] + ST[id*2+1];
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (l >= u && r <= v) return ST[id];

    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int32_t main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) { cin >> a[i]; update(1, 1, n, i, a[i]); }

    int t, u, v;
    while(q--) {
        cin >> t >> u >> v;
        if (t == 0) {
            swap(a[u], a[v]);
            update(1, 1, n, u, a[u]);
            update(1, 1, n, v, a[v]);
        }
        else cout << get(1, 1, n, u, v) << endl;
    }

    return 0;
}