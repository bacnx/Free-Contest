#include<bits/stdc++.h>
using namespace std;

string wine[] = {
    "ABSINTH",
    "TEQUILA",
    "VODKA",
    "WHISKEY",
    "WINE",
    "BEER",
    "BRANDY",
    "CHAMPAGNE",
    "GIN",
    "RUM",
    "SAKE"
};

int strToNum(string s) {
    int res = 0;
    for (int i : s) res = res * 10 + i - '0';
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if ('0' <= s.front() && s.front() <= '9') res += (strToNum(s) < 18);
        else for (int j = 0; j < 11; j++) res += (s == wine[j]);
    }

    cout << res;

    return 0;
}