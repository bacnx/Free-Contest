#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define MAX 1e5 + 5

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

struct DisjointSet {
    int n;
    vector<int> par;
    DisjointSet() {}
    DisjointSet(int _n) {
        n = _n;
        par.assign(n, -1);
    }

    int root(int v) {
        return par[v] < 0 ?
            v : (par[v] = root(par[v]));
    }

    bool merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return false;

        if (par[y] < par[x]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
};

int n;
vector<Edge> e;

void makeEdge() {
    vector<pii> nodeX, nodeY;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        nodeX.push_back(pii(x, i));
        nodeY.push_back(pii(y, i));
    }
    sort(nodeX.begin(), nodeX.end());
    sort(nodeY.begin(), nodeY.end());

    for (int i = 1; i < (int)nodeX.size(); i++) {
        e.push_back(Edge(nodeX[i].se, nodeX[i-1].se, nodeX[i].fi - nodeX[i-1].fi));
    }
    for (int i = 1; i < (int)nodeY.size(); i++) {
        e.push_back(Edge(nodeY[i].se, nodeY[i-1].se, nodeY[i].fi - nodeY[i-1].fi));
    }
}

void kruskal() {
    sort(e.begin(), e.end());
    DisjointSet ds(n);
    long long res = 0;

    for (Edge el : e) {
        if (ds.merge(el.u, el.v)) res += el.w;
    }
    cout << res;
}

int main() {
    cin >> n;
    makeEdge();
    kruskal();

    return 0;
}