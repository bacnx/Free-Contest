#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    string ans = "";

    for (int i = 1; i < n; i++)
        ans = "1" + ans + "0";
    
    cout << "1" << ans << "0" << '\n';
    cout << "01" << ans;

    return 0;
}