#include<bits/stdc++.h>
using namespace std;

#define int long long

int M;

int fb(int n) {
    double a = 1, b = 1;
    int cnt = 0;

    double sa = (1 + sqrt(5)/2);
    double sb = (1 - sqrt(5)/2);
    
    for (cnt = 1; cnt <= n; cnt++) {
        if (a * sa > (double)M) {
            cnt--;
            break;
        }
    }
}

int32_t main() {
    int n;
    cin >> n >> M;

    return 0;
}