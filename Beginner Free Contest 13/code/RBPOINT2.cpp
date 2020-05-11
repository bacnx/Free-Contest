#include <bits/stdc++.h>
using namespace std;

const int maxn = 100050;

int n, a[maxn], b[maxn];
int res = INT_MAX;

int search(int x) {
    int result;
    int l = 1, r = n, mid, kc = INT_MAX;
    while (l <= r) {
        mid = (l + r) / 2;
        if (kc > abs(a[x] - b[mid])){
            kc = abs(a[x] - b[mid]);
            result = mid;
        } else break;
        
        if (a[x] == b[mid]) return mid;
        if (a[x] < b[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    for (int i = 1; i <= n; i++) {
        res = min(res, abs(a[i] - b[search(i)]));
    }

    cout << res;

    return 0;
}