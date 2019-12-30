#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli MOD=1000000007;
lli DP[100005];
lli K;
lli solve(lli i)
{
	if(i==0)
		return 1;
	if(i<0)
		return 0;
	if(DP[i]!=-1)
		return DP[i];
	DP[i]=((solve(i-1)%MOD) + (solve(i-K)%MOD))%MOD;
	return DP[i]%MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T>>K;
	memset(DP,-1,sizeof(DP));
	solve(100000);
	for(lli i=1;i<=100000;i++)
	{
		DP[i]=((DP[i]%MOD)+ (DP[i-1]%MOD))%MOD;
	}
	while(T--)
	{
		lli a,b;
		cin>>a>>b;
		lli ans=DP[b]-DP[a-1];
		ans=(ans+MOD)%MOD;
		cout<<ans<<endl;

	}
}