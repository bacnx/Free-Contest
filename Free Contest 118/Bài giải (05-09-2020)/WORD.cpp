#include <bits/stdc++.h>
using namespace std;
string a[1009];
string tmp;
int main(){
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> tmp;
        string kq = "NO";
        for (int j = 1; j <= n; j++){
            if (tmp == a[j]){
                kq = "YES";
                break;
            }
        }
        cout << kq << endl;
    }
}
