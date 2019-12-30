#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli DP[105][505];
lli DP2[105][505];
lli Val[105];
lli Weight[105];
lli ans=0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli W,N;
	while(1)
	{
		ans=0;
		cin>>W>>N;
		if(W==0 && N==0)
			return 0;
		memset(DP,0,sizeof(DP));
		memset(Val,0,sizeof(Val));
		memset(Weight,0,sizeof(Weight));
		for(lli i=1;i<=N;i++)
		{
			cin>>Weight[i]>>Val[i];
		}
		for(lli i=0;i<=N;i++)
		{
			DP[i][0]=0;
			DP2[i][0]=0;
		}
		for(lli i=0;i<=W;i++)
		{
			DP[0][i]=0;
			DP2[0][i]=0;
		}
		for(lli j=1;j<=N;j++)
		{
			for(lli i=1;i<=W;i++)
			{
				if(Weight[j]>i)
				{
					DP[j][i]=DP[j-1][i];
					DP2[j][i]=DP2[j-1][i];
				}
				else
				{
					if(Val[j]+DP[j-1][i-Weight[j]]> DP[j-1][i])
					{
						DP[j][i]=Val[j]+DP[j-1][i-Weight[j]];
						//ans=ans+Weight[j];
						DP2[j][i]=(DP2[j-1][i-Weight[j]]+Weight[j] );
					}
					else if(Val[j]+DP[j-1][i-Weight[j]]== DP[j-1][i])
					{
						DP[j][i]=Val[j]+DP[j-1][i-Weight[j]];
						DP2[j][i]=min(DP2[j-1][i-Weight[j]]+Weight[j], DP2[j-1][i]);
					}
					else
					{
						DP[j][i]=DP[j-1][i];
						DP2[j][i]=DP2[j-1][i];
					}
				//	DP[j][i]=max(Val[j]+DP[j-1][W-Weight[j]], DP[j-1][i]);
				}
			}
		}

		cout<<DP2[N][W]<<" "<<DP[N][W]<<endl;
	}
}