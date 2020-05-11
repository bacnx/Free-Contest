#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

struct line { int x1, y1, x2, y2; };
bool cmp(const line &a, const line &b) { return a.x2 < b.x2; }

int n;
line a[maxn];

int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    sort(a+1, a+n+1, cmp);

    int x = 1;
    for (; x <= n; x++) if (a[x].x1 == 0 && a[x].y1 == 0) break;

    int res = 1;
    for (int i = x + 1; i <= n; i++)
        if (a[x].x2 >= a[i].x1 && a[x].y2 > a[i].y1 && a[x].x2 < a[i].x2) {
            res++;
            x = i;
            // cout << a[i].x1 << a[i].y1 << a[i].x2 << a[i].y2 << endl;
        }
    
    cout << res;
    
    return 0;
}