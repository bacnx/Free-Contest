#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int mul = a * b;
    
    if (mul > 0) cout << 1;
    else if (mul < 0) cout << -1;
    else cout << 0;

    return 0;
}