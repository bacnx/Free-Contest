#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int point[100005];
int nArea, area[100005];
bool visited[100005];

void visit(int u, int id) {
	point[u] = id;
	area[id]++;
	visited[u] = true;

	for (int v : adj[u]) if (!visited[v]) {
		visit(v, id);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	nArea = 0;
	for (int i = 1; i <= n; i++) if (!visited[i]) {
		visit(i, nArea);
		nArea++;
	}

	int ans = area[0];
	for (int i = 1; i <= n; i++) if (point[i] != 0) {
		ans = max(ans, area[0] + area[point[i]]);
	}
	cout << ans;

	return 0;
}