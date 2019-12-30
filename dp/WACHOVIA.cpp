#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	while(N--)
	{
		lli W,M;
		cin>>W>>M;
		lli weight[M+1];
		lli value[M+1];

		for(lli i=1;i<=M;i++)
		{
			cin>>weight[i]>>value[i];
		}
		lli DP[M+1][W+1];
		memset(DP,0,sizeof(DP));
		for(lli j=1;j<=M;j++)
		{
			for(lli i=1;i<=W;i++)
			{
				if(weight[j]>i)
				{
					DP[j][i]=DP[j-1][i];
				}
				else
				{
					DP[j][i]=max(DP[j-1][i-weight[j]]+value[j],DP[j-1][i]);
				}
			}
		}

		cout<<"Hey stupid robber, you can get "<<DP[M][W]<<"."<<endl;
	}
}