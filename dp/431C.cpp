#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli MOD=1000000007;

lli DP[105][2];

lli solve(lli n, lli k, lli d, lli flag, lli sum)
{
	if(sum>n)
		return 0;
	if(flag==1 && sum==n)
	{
		return 1;
	}
	else if(sum==n && flag==0)
	{
		return 0;
	}
	if(DP[sum][flag]!=-1)
		return DP[sum][flag]%MOD;
	lli a=0;
	for(lli i=1;i<=k;i++)
	{
		if(i>=d)
		{
			a=((a%MOD)+(solve(n,k,d,1,sum+i)%MOD))%MOD;
		}
		else
		{
			a=((a%MOD)+(solve(n,k,d,flag,sum+i)%MOD))%MOD;
		}
	}
	return DP[sum][flag]=(a%MOD);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k,d;
	cin>>n>>k>>d;
	memset(DP,-1,sizeof(DP));
	cout<<solve(n,k,d,0,0)%MOD<<endl;	
}