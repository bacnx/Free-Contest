#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

const int MAX = 1e4 + 4;
const int INF = 1e9;

struct Edge {
    int u, v, c;
    Edge() {}
    Edge(int _u, int _v, int _c) {
        u = _u, v = _v, c = _c;
    }
};

int n, m, k;
vector<int> p;
vector<Edge> e;
vector<int> adj[MAX];

void dijkstra(int u0) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> d(n + 1, INF);
    vector<bool> fre(n + 1, true);
    d[u0] = 0;
    pq.push(pii(0, u0));

    while (!pq.empty()) {
        int u = pq.top().se, l = pq.top().fi; pq.pop();
        if (!fre[u] || l != d[u]) continue;
        fre[u] = false;

        for (int i : adj[u]) {
            int v = e[i].v, c = e[i].c;
            if (!fre[v]) continue;
            if (d[u] + c < d[v]) {
                d[v] = d[u] + c;
                pq.push(pii(d[v], v));
            }
        }
    }

    if (d[e[p[0]].v] == INF) cout << "-1";
    else cout << d[e[p[0]].u];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int a; cin >> a; a--;
        p.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        e.push_back(Edge(u, v, c));
        adj[u].push_back(i);
    }

    dijkstra(e[p[0]].v);

    return 0;
}