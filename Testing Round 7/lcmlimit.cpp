#include<bits/stdc++.h>
using namespace std;

vector<int> prime;

void primeFilter() {
    int n = 1e6;
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) prime.push_back(i);
        for (int j = 2; i * j <= n; j++) isPrime[i * j] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    primeFilter();

    int n; cin >> n;

    int cnt = 1;
    cout << "1 ";
    for (int p : prime) {
        if (cnt == n) break;
        int tmp = 1;
        while (tmp <= 1e6) {
            tmp *= p;
            cout << tmp << ' ';
            cnt++;
            if (cnt == n) break;
        }
    }

    return 0;
}