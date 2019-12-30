#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	lli n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		lli q1[n+1];
		lli q2[n+1];
		lli x,y;
		for(lli i=1;i<=n;i++)
		{
			cin>>x>>y;
			q1[i]=x;
			q2[i]y;
		}

		lli dp[n+1][n+1];
		for(lli i=0;i<=n;i++)
		{
			
			for(lli j=0;j<=n;j++)
			{
				if(i==0 || j==0)
					dp[i][j]=0;
				if(q1[i]==q2[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}

		cout<<dp[n][n]<<endl;



	}
		
}