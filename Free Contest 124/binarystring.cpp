#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int cnt = 0, temp = 0;
        bool start = false;

        for (char c : s) {
            if (!start) {
                if (c == '1') start = true;
                continue;
            }
            if (c == '1') {
                cnt += temp;
                temp = 0;
            } else temp++;
        }
    
        if (start) cout << cnt << '\n';
        else cout << "-1\n";
    }

    return 0;
}