#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define ipair pair<ll int,ll int>
#define Ipair pair<int,int>
#define pri(c) priority_queue< c,vector< c>,greater<c> >
using namespace std;
ll int M=100000000000000;
ll int M1=1000000007;
ll int cnt[300005],parent[300005],rnk[300005];
typedef long long int lli;
struct queen
{
	ll int x;
	ll int y;
	ll int w;
};
 
// bool sortbysec(const queen &a,const queen &b)
// {
// 	return a.w<b.w;
// }
 
 
ll int fnd(ll int x)
{
	if(x!=parent[x])
	parent[x]=fnd(parent[x]);
	return parent[x];
}
 
void merge(ll int x,ll int y)
{
	x=fnd(x);
	y=fnd(y);
	if(rnk[x]>rnk[y])
	{
		parent[y]=x;
		cnt[x]+=cnt[y];
	}
	else
	{
		parent[x]=y;
		cnt[y]+=cnt[x];
	}
	if(rnk[x]==rnk[y])
	rnk[y]++;
}
 
ll int fast_exp(ll int base,ll int ep)
{
	ll int ans=1;
	base=base%M1;
	while(ep>0)
	{
		if(ep%2!=0)
		{
			ans=ans*base;
			ans=ans%M1;
		}
		base=base*base;
		base=base%M1;
		ep/=2;
	}
	ans=ans%M1;
	return ans;
}
int main()
{
	ll int n,i,x1,x2,x3,x4,x5,x6,ans;
	cin>>n;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	vector<queen> v(n-1);
	for(i=0;i<n-1;i++)
	{
		cin>>v[i].x>>v[i].y;
		cout<<v[i].x<<v[i].y<<endl;
	}
	//sort(all(v),sortbysec);
	vector<lli> w(n-1);
	for(lli i=0;i<n-1;i++)
	{
		cin>>w[i];
	}
	for(i=0;i<200005;i++)
	{
		rnk[i]=0;
		parent[i]=i;
		cnt[i]=1;
	}
	ans=1;
	vector<lli> z;
	for(i=0;i<n-1;i++)
	{
		//cout<<parent[v[i].x]<<" "<<parent[v[i].y]<<endl;
		x1=fnd(v[i].x);
		x2=fnd(v[i].y);
		x5=x1;
		x6=x2;
		x1=cnt[x5];
		x2=cnt[x6];
		x3=x1*x2;
		z.push_back(x3);
		cout<<x3<<" "<<x1<<" "<<x2<<endl;
		//x3=x3%M1;
		// x4=fast_exp(v[i].w,x3);
		// x4=x4%M1;
		// ans=ans*x4;
		// ans=ans%M1;
		merge(x5,x6);
		cout<<cnt[x5]<<" "<<cnt[x6]<<endl;
	}
	sort(z.begin(),z.end());
	sort(w.begin(),w.end());
	ans=0;
	for(lli i=1;i<=n;i++)
	{
		cout<<cnt[i]<<endl;
	}
	for(lli i=0;i<n-1;i++)
	{
		lli x4=(w[i]*z[i]);
		ans=ans+x4;
	}

	cout<<ans<<endl;
}
	
