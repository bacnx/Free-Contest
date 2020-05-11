#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll n, a; cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }

    ll res = 0;
    while (pq.size() > 1) {
        a = pq.top(); pq.pop();
        a += pq.top(); pq.pop();
        res += a*a;
        pq.push(a);
    }
    cout << res;

    return 0;
}