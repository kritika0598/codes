#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli mod=1000000007;
lli DP[205];
lli solve(lli Arr[], lli i, lli N, lli K)
{
	if(i==N)
	{
		return 1;
	}
	lli x=0;
	if(DP[i]!=-1)
		return DP[i];
	for(lli j=i;j<N;j++)
	{
		if(Arr[j]-Arr[i]<=K)
		{
			x=(x%mod+(solve(Arr,j+1,N,K))%mod)%mod;
		}
		else
		{
			break;
		}
	}
	return DP[i]=x%mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	sort(Arr,Arr+N);
	memset(DP,-1,sizeof(DP));
	cout<<solve(Arr,0,N,K)<<endl;
}