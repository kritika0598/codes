#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[20][1002];
lli solve(lli N, lli W, lli i, lli value [], lli weight[])
{
	if(i>=N)
	{
		return 0;
	}
	if(DP[i][W]!=-1)
		return DP[i][W];
	lli x=INT_MIN;
	if(weight[i]<=W)
	{
		x=max(x,value[i]+solve(N,W-weight[i],i+1,value,weight));
	}
	x=max(x,solve(N,W,i+1,value,weight));
	return DP[i][W]=x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,W;
		cin>>N>>W;

		lli value[N];
		for(lli i=0;i<N;i++)
		{
			cin>>value[i];
		}
		lli weight[N];
		for(lli i=0;i<N;i++)
		{
			cin>>weight[i];
		}
		memset(DP,-1,sizeof(DP));
		cout<<solve(N,W,0,value,weight)<<endl;
	}	
}