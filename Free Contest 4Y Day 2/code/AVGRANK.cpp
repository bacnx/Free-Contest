#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
typedef pair<int, int> ii;
bool cmp(const ii &a, const ii &b) {return a.second > b.second;}

int n, m;
// vector<int> subfull[maxn];
ii point[maxn];
int Rank[maxn], sumrank[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;

    point[0].second = -1;
    for (int i = 1; i <= n; i++) { 
        point[i].first = i; 
        point[i].second = 0; 

    }

    int k, c;
    for (int i = 1; i <= m; i++) {
        cin >> k;
        while (k--) {
            cin >> c;
            point[c].second++;
            // subfull[c].push_back(i);
        }
        // for (int i = 1; i <= n; i++)
        sort(point+1, point+n+1, cmp);
        for (int i = 1; i <= n; i++) {
            if (point[i].second == point[i-1].second) Rank[i] = Rank[i-1];
            else Rank[i] = i;
            sumrank[i] += Rank[i];
            cout << Rank[i] << " ";
        }
        cout << endl;
    }

    // for (int i = 1; i <= n; i++)
        // cout << setprecision(7) << fixed << (double)sumrank[i]/m << endl;
        // cout << sumrank[i] << endl;

    return 0;
}