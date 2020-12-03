#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e5+5;

int n;
vector<pii> adj[MAX];
int res[MAX], mx = 0;

void bfs() {
    queue<pii> q;
    q.push(pii(1, 0));

    while (!q.empty()) {
        int u = q.front().first, c = q.front().second; q.pop();
        int cnt = 0;
        for (pii i : adj[u]) if (res[i.second] == 0) {
            cnt++; if (cnt == c) cnt++;
            res[i.second] = cnt;
            mx = max(mx, cnt);
            q.push(pii(i.first, cnt));
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(pii(v, i));
        adj[v].push_back(pii(u, i));
    }

    bfs();

    cout << mx << '\n';
    for (int i = 1; i < n; i++) cout << res[i] << '\n';

    return 0;
}