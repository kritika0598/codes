#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli MOD = 1000000007;
lli DP[2005][2005];
lli N,K;
lli solve( lli i, lli ind)
{
	if(ind==K)
		return 1;
	if(DP[ind][i])
		return DP[ind][i];
	lli ans=0;
	{
		for(lli j=1;j*i<=N;j++)
		{
			//if((j%i)==0)
			{
				ans=((ans%MOD)+(solve(j*i,ind+1)%MOD))%MOD;
			}
		}
	}
	return DP[ind][i]=ans%MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//lli N,K;
	cin>>N>>K;
	//memset(DP,-1,sizeof(DP));
	cout<<solve(1,0)<<endl;
}