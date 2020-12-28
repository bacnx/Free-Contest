#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
#define fi first
#define se second

struct DisjointSet {
    int n;
    vector<int> par;   
    DisjointSet() {}

    DisjointSet(int _n) {
        n = _n;
        par.assign(n + 1, -1);
    }

    int root(int v) {
        return par[v] < 0 ?
            v : (par[v] = root(par[v]));
    }

    bool isSame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return ;

        if (par[x] < par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
};

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }

    bool operator < (const Edge &b) {
        return w < b.w;
    }
};

const int MAX = 4e3 + 3;

int n, m;
vector<Edge> e;
vector<pii> adj[MAX];
ll sumEdgeAdj;
int maxEdge[MAX][MAX];

void kruskal() {
    DisjointSet ds(n);
    int cnt = 0;
    sumEdgeAdj = 0;

    for (Edge i : e) {
        int u = i.u, v = i.v, w = i.w;
        if (!ds.isSame(u, v)) {
            ds.merge(u, v);
            cnt++;
            sumEdgeAdj += w;
            adj[u].push_back(pii(v, w));
            adj[v].push_back(pii(u, w));
        }
        if (cnt == n-1) break;
    }
}

void bfs(int u0) {
    queue<int> q;
    q.push(u0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (pii i : adj[u]) if (maxEdge[u0][i.fi] == 0) {
            int v = i.fi, w = i.se;
            maxEdge[u0][v] = max(maxEdge[u0][u], w);
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e.push_back(Edge(u, v, w));
    }
    
    sort(e.begin(), e.end());
    kruskal();
    for (int i = 1; i <= n; i++) bfs(i);

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << sumEdgeAdj - maxEdge[u][v] << '\n';
    }

    return 0;
}

/*
 * tạo cây khung nhỏ nhất bằng kruskal
 * Q: (A, B) = edgeMax(A -> B)

*/