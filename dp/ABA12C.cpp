#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[105][105];
lli solve(lli Arr[], lli i, lli K, lli c, lli N)
{
	if(N<0)
	{
		return INT_MAX;
	}
	if(i==K)
	{
		if(c==0)
		{
			if(N>=0)
			{
				return 0;
			}
		}
		return INT_MAX;
	}
	if(DP[i][c]!=-1)
		return DP[i][c];
	lli x=INT_MAX;
	if(Arr[i]==-1)
	{
		return DP[i][c]=solve(Arr,i+1,K,c,N);
	}
	else
	{
		
		if(i>c)
		{
			x=solve(Arr,i+1,K,c,N);
		}
		else
		{
			x=min(x,min(solve(Arr,i+1,K,c,N),Arr[i]+solve(Arr,i+1,K,c-i,N-1)));
		}

	}
	return DP[i][c]=x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N, K;cin>>N>>K;
		lli arr[K+1];
		for(lli i=1;i<=K;i++)
		{
			cin>>arr[i];
		}
		memset(DP,-1,sizeof(DP));
		lli x=solve(arr,1,K+1,K,N);
		if(x>=INT_MAX)
			cout<<-1<<endl;
		else
			cout<<x<<endl;

	}
}