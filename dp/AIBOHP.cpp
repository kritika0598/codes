#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[6105][6105];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		string a="";
		for(lli i=s.length()-1;i>=0;i--)
		{
			a=a+s[i];
		}
		//cout<<a<<endl;
		lli N=s.length();
		//lli DP[N+1][N+1];
		memset(DP,0,sizeof(DP));
		for(lli i=0;i<=N;i++)
		{
			DP[i][0]=0;
			DP[0][i]=0;
		}

		for(lli i=1;i<=N;i++)
		{
			for(lli j=1;j<=N;j++)
			{
				if(a[i-1]==s[j-1])
				{
					DP[i][j]=DP[i-1][j-1]+1;
				}
				else
				{
					DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
				}
			}
		}

		// for(lli i=0;i<=N;i++)
		// {
		// 	for(lli j=0;j<=N;j++)
		// 	{
		// 		cout<<DP[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;

		cout<<N-DP[N][N]<<endl;
	}
		
}