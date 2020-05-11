#include <bits/stdc++.h>
using namespace std;

const int maxn = 5001;

int n, m;
int c[maxn], d[maxn];
vector<int> ds1[maxn], ds2[maxn];

queue<int> q;
int l[maxn];
bool kill[maxn];

void loang(int u0) {
    for (int i = 1; i <= n; i++) kill[i] = false;
    kill[u0] = true;
    while (!q.empty()) q.pop();
    q.push(u0);
    l[u0] = 0;

    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        if (l[u] == d[u0]) break;
        for (int i = 0; i < (int)ds1[u].size(); i++) {
            v = ds1[u][i];
            if (!kill[v]) {
                kill[v] = true;
                q.push(v);
                l[v] = l[u] + 1;
                ds2[u0].push_back(v);
            }
        }
    }
}

void dijstra(int u0) {
    for (int i = 1; i <= n; i++) { l[i] = INT_MAX; kill[i] = false; }
    l[u0] = 0;

    int mn;
    int u, v;
    while (true) {
        mn = INT_MAX;
        for (int i = 1; i <= n; i++)
            if (!kill[i] && mn > l[i]) { mn = l[i]; u = i; }
        if (u == n) break;
        kill[u] = true;
        for (int i = 0; i < (int)ds2[u].size(); i++) {
            v = ds2[u][i];
            if (!kill[v]) l[v] = min(l[v], l[u] + c[u]);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> d[i];
    
    int u, v;
    while (m--) {
        cin >> u >> v;
        ds1[u].push_back(v);
        ds1[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) loang(i);

    dijstra(1);
    cout << l[n];

    return 0;
}