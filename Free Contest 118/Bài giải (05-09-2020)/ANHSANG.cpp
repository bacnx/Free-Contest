#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define double long double
#define pb push_back
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double eps = 1e-14;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

typedef Point<double> P;
const int maxn = 50000;
int n;
P orig;
P sweep;
vector<P> poly;

struct Segment {
	P a,b;
	bool operator<(Segment o) const {
		pair<int,P> i1 = lineInter(orig,sweep,a,b);
		pair<int,P> i2 = lineInter(orig,sweep,o.a,o.b);
		assert(i1.first==1 && i2.first==1);
		return (orig-i1.Y).dist()<(orig-i2.Y).dist();
	}
	bool operator==(Segment o) const {
		return (a==o.a && b==o.b);
	}
};

void input() {
	cin >> orig.x >> orig.y >> n;
	rep(i,0,n) {
		double x,y;
		cin >> x >> y;
		poly.pb(P(x,y)-orig);
	}
	orig = P(0,0);
}

vector<P> v;
bool isUpper(P x) {
	if (x.y>0) return true;
	if (x.y<0) return false;
	if (x.y==0 and x.x>0) return true;
	return false;
}
bool cmp(P x,P y) {
	bool x1 = isUpper(x), y1 = isUpper(y);
	if (x1!=y1) return x1>y1;
	return (x.cross(y)>0);
}
int index(vector<P>& v,P p) {
	int res = distance(v.begin(),lower_bound(v.begin(),v.end(),p,cmp));
	//cout << "index " << p << ' ' << v[res] << endl;
	assert(res!=sz(v));
	assert(v[res].cross(p)==0);
	return res;
}
int nxt(vector<P>& v,int x) { return (x+1)%sz(v); }

vector<Segment> add[maxn+1];
vector<Segment> del[maxn+1];
set<Segment> cur;

void process() {
	rep(i,0,n) { v.pb(poly[i]); }
	sort(v.begin(),v.end(),cmp);
	v.erase(unique(all(v),[](P x,P y) { return x.cross(y) == 0; }),v.end());
	//cout << sz(v) << endl;
	sweep = v[0]+v[sz(v)-1];
	rep(i,0,n) {
		if (index(v,poly[i])==index(v,poly[nxt(poly,i)])) continue;
		P a = poly[i], b = poly[nxt(poly,i)];
		if (a.cross(b)<0) swap(a,b);
		//cout << a << ' ' << b << ' ' << index(v,a) << ' ' << index(v,b) << ' ' << sz(cur) << endl;
		add[index(v,a)].pb({a,b});
		del[index(v,b)].pb({a,b});
		if (index(v,a) > index(v,b)) {
			int tmp = sz(cur);
			cur.insert({a,b});
			assert(tmp+1==sz(cur));
		}
	}
}

void solve() {
	double res = 0.0;
	rep(i,0,sz(v)) {
		rep(j,0,sz(del[i])) {
			//cout << "del " << i << ' ' << del[i][j].a << ' ' << del[i][j].b << endl;
			assert(cur.count(del[i][j]));
			int tmp = sz(cur);
			cur.erase(del[i][j]);
			//assert(tmp-1==sz(cur));
		}
		sweep = v[nxt(v,i)]+v[i];
		rep(j,0,sz(add[i])) {
			int tmp = sz(cur);
			cur.insert(add[i][j]);
			assert(tmp+1==sz(cur));
		}
		
		assert(sz(cur)>0);
		Segment s = *cur.begin();
		P i1 = lineInter(s.a,s.b,v[i],orig).Y;
		P i2 = lineInter(s.a,s.b,orig,v[nxt(v,i)]).Y;
		//cout << s.a << ' ' << s.b << ' ' << i1 << ' ' << i2 << ' ' << sz(cur) << endl;
		res+=abs(orig.cross(i1,i2));
	}
	cout << setprecision(2) << fixed << res*0.5 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	input();
	process();
	solve();
	return 0;
}

