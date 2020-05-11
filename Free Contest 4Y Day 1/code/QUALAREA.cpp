#include <bits/stdc++.h>
using namespace std;

const int maxn = 302;
const double eps = 0.000001;

struct point { int x, y; };

int ccw(point a, point b, point c) {
    double t = (double)((b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x));
    if (t < eps) return 0;
    if (t > 0) return 1;
    return -1;
}

int n;
point p[maxn];
vector<point> w;
point root;

bool cmp(const point &a, const point &b) { return (ccw(a, root, b) == 1); }

int area(point a, point b, point c, point d) {
    int res = 0;
    res += (b.x - a.x) * (b.y + a.y);
    res += (c.x - b.x) * (c.y + b.y);
    res += (d.x - c.x) * (d.y + c.y);
    res += (a.x - d.x) * (a.y + d.y);
    return abs(res);
}

point pt[5];
int h[5], res = 0;
bool Kill[maxn];
void hv(int x) {
    if (x == 5) { res = max(res, area(pt[h[1]], pt[h[2]], pt[h[3]], pt[h[4]])); return; }
    for (int i = 1; i <= 4; i++)
        if (!Kill[i]) {
            Kill[i] = true;
            h[x] = i;
            hv(x+1);
            Kill[x] = false;
        }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;


    root = p[1];
    int csr = 1;
    for (int i = 2; i <= n; i++) 
        if (root.y > p[i].y || (root.y == p[i].y && root.x > p[i].x)) {root = p[i]; csr = i;}
    swap(p[1], p[csr]);
    sort(p + 2, p + n + 1, cmp);

    // cout << area(p[1], p[2], p[4], p[3]);
    // for (int i = 1; i <= n; i++) cout << p[i].x << " " << p[i].y << endl;
    cout << area(p[1], p[2], p[3], p[4]);
    for (int i1 = 1; i1 <= n-3; i1++) {
        pt[1] = p[i1];
        for (int i2 = i1+1; i2 <= n-2; i2++) {
            pt[2] = p[i2];
            for (int i3 = i2+1; i3 <= n-1; i3++) {
                pt[3] = p[i3];
                for (int i4 = i3+1; i4 <= n; i4++) {
                    pt[4] = p[i4];
                    hv(1);
                }
            }
        }
    }
    cout << res;

    return 0;
}