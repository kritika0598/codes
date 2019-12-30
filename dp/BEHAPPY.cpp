#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli N,M;
lli count1=0;
lli a[101];
lli b[101];
bool dp[101][101];
lli dp1[101][101];

lli mod=1000000007;

lli solve(lli index, lli rem)
{
	//cout<<index<<" "<<rem<<endl;
	//else
	//dp[index][rem]=0;
	if(dp[index][rem])
		return dp1[index][rem]%mod;

	dp[index][rem]=true;
	if(index>N-1)
	{
		if(rem==0)
		{
			//cout<<count1<<endl;
			dp1[index][rem]++;
			return dp1[index][rem]%mod;
			//return dp[index][rem] =true;
		}
		return 0;
	}

	for(lli j=a[index] ;j <=rem , j<=b[index];j++)
	{
	//	if(dp[index+1][rem-j])
			//dp1[index][rem]=dp1[index+1][rem-j];
	//	else
		{
			dp1[index][rem]+=solve(index+1,rem-j)%mod;			
		}	
	}
	return dp1[index][rem]%mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--)
	{
		cin>>N>>M;

		for(lli i=0;i<N;i++)
		{
			cin>>a[i]>>b[i];
		}

		for(lli i=0;i<=100;i++)
		{
			for(lli j=0;j<=100;j++)
			{
				dp[i][j]=false;
			}
		}
		for(lli i=0;i<=100;i++)
		{
			for(lli j=0;j<=100;j++)
			{
				dp1[i][j]=0;
			}
		}

		cout<<solve(0,M)%mod<<endl;
		
	}
	
}