#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
const int maxm = 2e4;
const int maxk = 15;
const int oo = 1e9+7;

typedef pair<int, int> pii;

struct Edge { int u, v, w; };

int n, m, k, c[maxk], d[maxk][maxn], cyc[1<<maxk], dp[1<<maxk];
Edge e[maxm];
vector<int> g[maxn];

void dijkstra(int s, int d[]) {
	for (int i = 0; i < n; i++) 
		d[i] = oo;
	d[s] = 0;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(d[s], s));

	vector<bool> avail(n, true);

	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (!avail[u]) continue;

		avail[u] = false;
		for (int i = 0; i < (int)g[u].size(); i++) {
			int j = g[u][i];
			int v = e[j].v, w = e[j].w;

			if (avail[v] && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push(pii(d[v], v));
			}
		}
	}
}

void getCyc() {
	for (int mask = 0; mask < 1<<k; mask++)
		cyc[mask] = oo;

	for (int first = 0; first < k; first++) {
		vector<vector<int> > dp(1<<k, vector<int>(k, oo));
		dp[1<<first][first] = 0;

		for (int mask = 0; mask < 1<<k; mask++) {
			for (int i = 0; i < k; i++) {
				if (dp[mask][i] == oo) continue;
				for (int j = 0; j < k; j++) {
					if (mask&(1<<j)) continue;
					dp[mask|(1<<j)][j] = min(dp[mask|(1<<j)][j], dp[mask][i] + d[i][e[c[j]].u]);
				}
			}
		}

		for (int mask = 0; mask < 1<<k; mask++)
			for (int i = 0; i < k; i++)
				cyc[mask] = min(cyc[mask], dp[mask][i] + d[i][e[c[first]].u]);
	}
}

int solve() {
	for (int mask = 0; mask < 1<<k; mask++) {
		dp[mask] = cyc[mask];
		for (int sub = mask; sub > 0; sub = (sub-1)&mask)
			dp[mask] = min(dp[mask], cyc[sub] + dp[mask^sub]);
	}
	return dp[(1<<k)-1];
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		c[i]--;
	}
	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].u--; e[i].v--;
		g[e[i].u].push_back(i);
	}

	for (int i = 0; i < k; i++)
		dijkstra(e[c[i]].v, d[i]);

	getCyc();

	int ans = solve();
	if (ans == oo) ans = -1;
	cout << ans;

	return 0;
}