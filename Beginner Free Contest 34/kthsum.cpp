#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

struct Multip {
    int value;
    int x, y;
    
    bool operator < (Multip a) const {
        return value > a.value;
    }

    Multip(int _value = 0, int _x = 0, int _y = 0) {
        value = _value;
        x = _x;
        y = _y;
    }
};

int n, k, a[100005], b[100005];
map<pair<int, int>, int> mapCount;
priority_queue<Multip> pq;

void increaseCount(int x, int y) {
    if (++mapCount[pii(x, y)] == 2) {
        pq.push(Multip(a[x] + b[y], x, y));
    }
}

void solve() {
    pq.push(Multip(a[1] + b[1], 1, 1));

    while (k--) {
        Multip u = pq.top(); pq.pop();
        cout << u.value << ' ';
        increaseCount(u.x + 1, u.y);
        increaseCount(u.x, u.y + 1);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++) {
        mapCount[pii(i, 1)]++;
        mapCount[pii(1, i)]++;
    }
    
    solve();

    return 0;
}