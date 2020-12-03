#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e5+5;

int n;
pii a[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);

    int res = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++)
        res += a[i].second < a[j].second;
    
    cout << res;

    return 0;
}