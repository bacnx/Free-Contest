#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 1e6 + 6;

int n, x, a[MAX];
ll sum[MAX];

ll getMatrixValue(int i, int j, int c) {
    int ii = i + c - 1, jj = j + c - 1;
    if (max(ii, jj) > n) return -1;
    return 1LL * c * (sum[ii] - sum[i-1] + sum[jj] - sum[j-1]);
}

bool binaryFind(int i, int j) {
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        ll tmp = getMatrixValue(i, j, mid);

        if (tmp == 1LL * x) return true;
        if (tmp == -1 || tmp > x) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("luckysq.inp", "r", stdin);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        res += binaryFind(i, j);
    
    cout << res;

    return 0;
}