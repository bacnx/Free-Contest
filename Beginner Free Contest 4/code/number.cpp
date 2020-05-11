#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b = 0, a, res = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        res += (a+b)/2;
        b = (a+b)%2;
    }
    cout << res;

    return 0;
}