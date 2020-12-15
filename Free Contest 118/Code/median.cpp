#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}

int n, a[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);

    vector<int> newArr;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = i; j <= n; j++) {
            v.push_back(a[j]);
            sort(v.begin(), v.end());
            newArr.push_back(v[v.size()/2]);
        }
    }
    sort(newArr.begin(), newArr.end());
    cout << newArr[newArr.size()/2];

    return 0;
}