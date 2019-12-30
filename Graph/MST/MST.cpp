#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

pair<lli,pair<lli,lli>> v[10005];
lli id[100005];
lli M,N;

lli root(lli x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
}

lli union1(lli x, lli y)
{
	lli p=root(x);
	lli q=root(y);

	id[p]=id[q];
}


lli kruskal()
{
	lli x,y;

	lli cost=0;
	for(lli i=0;i<M;i++)
	{
		x=v[i].second.first;
		y=v[i].second.second;

		if(root(x)!=root(y))
		{
			cost+=v[i].first;
			union1(x,y);
		}
	}

	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	lli x,y,z;
	lli dis[N+1];
	lli a[M+1];


	for(lli i=0;i<=N;i++)
	{
		id[i]=i;
	}

	for(lli i=0;i<M;i++)
	{
		cin>>x>>y>>z;
		v[i]=make_pair(z,make_pair(x,y));
	}

	for(lli i=1;i<=N;i++)
	{
		dis[i]=1000000009;
	}

	sort(v,v+M);

	lli ans=kruskal();

	cout<<ans<<endl;
}
