#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool flag=false;
lli DP[100005][8];

lli solve(map<lli,map<lli,lli>> m, lli i, lli prev, lli N)
{
	map<lli,lli> :: iterator itr;
	if(i==N)
	{
		lli x=INT_MIN;
		for(itr=m[i].begin();itr!=m[i].end();itr++)
		{
			if(itr->first!=prev)
			{
				x=max(x,itr->second);
				flag=true;
			}

		}
		return x;
	}
	lli x=INT_MIN;
	if(DP[i][prev]!=-1)
		return DP[i][prev];
	for(itr=m[i].begin();itr!=m[i].end();itr++)
	{
		if(itr->first!=prev)
			x=max(x,itr->second+solve(m,i+1,itr->first,N));
	}

	return DP[i][prev]=x;


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,M;
		cin>>N>>M;
		flag=false;
		map<lli, map<lli,lli>> m;
		for(lli i=0;i<=N;i++)
		{
			for(lli j=0;j<7;j++)
			{
				DP[i][j]=-1;
			}
			
		}
		for(lli i=0;i<M;i++)
		{
			lli b,c,v;
			cin>>b>>c>>v;
			m[b][c]=max(m[b][c],v);
		}
		map<lli,lli> :: iterator itr;
		lli x=INT_MIN;
		for(itr=m[1].begin();itr!=m[1].end();itr++)
		{
			x=max(x, itr->second+solve(m,2,itr->first,N));
			//cout<<x<<" "<<itr->first<<" "<<itr->second<<endl;
		}

		if(flag)
			cout<<x<<endl;	
		else
			cout<<-1<<endl;	
	}
}