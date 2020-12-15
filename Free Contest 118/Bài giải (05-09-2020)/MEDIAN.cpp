#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const int oo = 1e9 + 7;

int n, a[MAXN], b[MAXN];

struct BIT {
private:
    vector<int> t;
public:
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i))
            t[i] += x;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i))
            res += t[i];
        return res;
    }
};

long long C2(long long n) {return n*(n+1)/2;}

bool Check(int mid) {
    vector<int> d(n+1);
    for(int i = 1; i <= n; ++i)
        d[i] = d[i-1] + ((a[i] >= b[mid]) ? 1 : -1);

    BIT t(2*n);
    long long cnt = 0;
    for(int i = 1; i <= n; ++i) {
        t.update(d[i-1] + n, 1);
        cnt += t.query(d[i] + n);
    }

    return (2*cnt >= C2(n));
}

int main () {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; ++i)
        b[i] = a[i];
    sort(b+1, b+n+1);

    int lo = 1, hi = n, res = 0;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            lo = mid+1;
        } else hi = mid-1;
    }

    printf("%d\n", b[res]);

    return 0;
}

