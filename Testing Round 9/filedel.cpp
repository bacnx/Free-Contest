#include<bits/stdc++.h>
using namespace std;

int n, q;
stack<int> inStr[26];
bool fre[100005];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) {
            c -= 'a';
            if (inStr[c].empty() || inStr[c].top() != i)
                inStr[c].push(i);
        }
    }

    memset(fre, true, sizeof fre);
    int ans = n;
    while (q--) {
        char c; cin >> c; c -= 'a';
        while (!inStr[c].empty()) {
            int u = inStr[c].top(); inStr[c].pop();
            if (fre[u]) {
                fre[u] = false;
                ans--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}