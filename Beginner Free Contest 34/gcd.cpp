#include<bits/stdc++.h>
using namespace std;

int n, a[100005];
int countPrime[10004];
vector<int> prime;
int maxPrime;

void filterPrime() {
    int n = 10000;
    vector<bool> fp(n, true);
    for (int i = 2; i <= n; i++) if (fp[i]) {
        prime.push_back(i);
        for (int j = 2; j * i <= n; j++) {
            fp[i * j] = false;
        }
    }
}

void primeFactorization(int x) {
    for (int p: prime) {
        if (x % p == 0) {
            countPrime[p]++;
            maxPrime = max(maxPrime, p);
        }
        while (x % p == 0) {
            x /= p;
        }
        if (x == 1) break;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int gcdOfArray = a[1];
    for (int i = 2; i <= n; i++) {
        gcdOfArray = __gcd(gcdOfArray, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        a[i] /= gcdOfArray;
    }

    filterPrime();

    maxPrime = 0;
    for (int i = 1; i <= n; i++) {
        primeFactorization(a[i]);
    }

    int ans = -1;
    for (int i = 2; i <= maxPrime; i++) {
        ans = max(ans, countPrime[i]);
    }

    if (ans != -1) {
        ans = n - ans;
    }
    cout << ans;

    return 0;
}