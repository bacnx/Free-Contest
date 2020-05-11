#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q, dif[200001], st[1000000];

void update(int id, int l, int r, int i, int v) {
    if (i < l || i > r) return ;
    if (l == r) { st[id] = v; return ; }

    int mid = (l+r)/2;
    update(id*2, l, mid, i, v);
    update(id*2+1, mid+1, r, i, v);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && v >= r) return st[id];

    int mid = (l+r)/2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> dif[i];
    for (int i = 1; i < n; i++) {
        dif[i] = dif[i] - dif[i+1];
        if (dif[i] > 0) update(1, 1, n-1, i, 1);
    }

    int a, b, c;
    while (q--) {
        cin >> a >> b >> c;
        dif[a-1] -= c;
        dif[b] += c;   
        if (dif[a-1] > 0) update(1, 1, n-1, a-1, 1);
        else update(1, 1, n-1, a-1, 0);
        if (dif[b] > 0) update(1, 1, n-1, b, 1);
        else update(1, 1, n-1, b, 0);
        cout << st[1] << endl;
    }
    
    return 0;
}