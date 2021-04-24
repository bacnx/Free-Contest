#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, k; cin >> n >> k;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        pq.push((ll)a);
    }

    ll cost = 0, sum = 0;
    int temp = k;
    while (pq.size() > 1 || sum != 0) {
        ll a = pq.top(); pq.pop();
        sum += a;
        if (temp == k) {
            cost -= a;
        }
        temp--;
        if (temp == 0 || pq.empty()) {
            cost += a;
            pq.push(sum);
            sum = 0;
            temp = k;
        }
    }

    cout << pq.top() << '\n' << cost;

    return 0;
}