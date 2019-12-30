#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
string a,b;
lli DP[4001][4001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{

		cin>>a>>b;
		lli n=a.length();
		lli m=b.length();
		memset(DP,0,sizeof(DP));
		for(lli i=0;i<=n;i++)
		{
			for(lli j=0;j<=m;j++)
			{
				if(i==0 && j==0)
				{
					DP[i][j]=0;
				}
				else if(i==0)
				{
					DP[i][j]=j;
				}
				else if(j==0)
				{
					DP[i][j]=i;
				}
				else
				{
					if(a[i-1]==b[j-1])
					{
						DP[i][j]=(DP[i-1][j-1]);
					}
					else
					{
						DP[i][j]=min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))+1;
					}
				}
			}
		}

	//	lli ans=max(m,n);
		lli ans=DP[n][m];
		cout<<ans<<endl;
	}
}