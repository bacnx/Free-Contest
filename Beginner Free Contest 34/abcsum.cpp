#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a == b + c || b == a + c || c == a + b) {
        cout << '1';
    } else {
        cout << '0';
    }

    return 0;
}