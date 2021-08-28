#include<bits/stdc++.h>
using namespace std;

struct Account {
    string username;
    string password;
    int login;
};

int n, k;
Account acc[102];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> acc[i].username >> acc[i].password;
        acc[i].login = 0;
    }

    cin >> k;
    while (k--) {
        string username, password;
        cin >> username >> password;
        for (int i = 0; i < n; i++) {
            if (username == acc[i].username && password == acc[i].password) {
                acc[i].login++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << acc[i].login << ' ';
    }

    return 0;
}