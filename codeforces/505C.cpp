#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
map<lli,lli> m;
lli DP[30005][250*2];
 bool vis[30005][250*2]={};
lli solve(lli i, lli pre,lli d)
{
	lli j=pre-(d-250);
	if(i>=30001)
	{
		return 0;
	}
	if(vis[i][j])
		return DP[i][j];
	vis[i][j]=true;
	lli x;
	if(pre-1>0)
	{
		x=m[i]+max(solve(i+pre,pre,d),max(solve(i+pre-1,pre-1,d),solve(i+pre+1,pre+1,d)));
	}
	else
	{
		x=m[i]+max(solve(i+pre,pre,d),solve(i+pre+1,pre+1,d));
	}
	return DP[i][j]=x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,d;
	cin>>N>>d;
	lli maxi=d;

	for(lli i=0;i<N;i++)
	{
		lli x;
		cin>>x;
		if(x>maxi)
			maxi=x;
		m[x]++;
	}
	//memset(DP,-1,sizeof(DP));
	cout<<solve(d,d,d)<<endl;
}