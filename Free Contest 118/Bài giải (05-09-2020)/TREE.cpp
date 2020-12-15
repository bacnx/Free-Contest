#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

int n,x,y,ans,m,a[100],b[100];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>x>>y;
	if (x==y) {cout<<0;return 0;}
	a[0]=-1;b[0]=-1;
	a[1]=x;n=1;
	while (a[n]!=1) n++,a[n]=a[n-1]/2;
	b[1]=y;m=1;
	while (b[m]!=1) m++,b[m]=b[m-1]/2;
	ans=1;
	while (a[n-ans]==b[m-ans]) ans++;
	ans=m+n-2*ans;
	cout<<ans;
}

