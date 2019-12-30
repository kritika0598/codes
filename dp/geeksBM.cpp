#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Arr[10][100];
lli N;
lli dp[1<<11];


lli ans()
{
	for(lli i=0;i<(1<<N);i++)
	{
		dp[i]=0;
	}

	// for(lli i=0;i<N;i++)
	// {
	// 	dp[1<<i]=cs[i];
	// }
	dp[(1<<N)-1]=1;
	for(lli i=(1<<N)-1;i>=0;i--)
	{
		for(lli j=0;j<=3;j++)
		{
			lli x=__builtin_popcount(i);

			if(!(i&(1<<j)) && Arr[x][j])
			{
				dp[i]+=dp[i|(1<<j)];
				
			}

		//	cout<<i<<" "<<j<<" "<<dp[i]<<endl;
		}

		//cout<<i<<" "<<dp[]
	}

	return dp[0];
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// lli T;
	// cin>>T;
	// while(T--)
	// {
	// 	cin>>N;
	// 	memset(Arr,0,sizeof(Arr));

	// 	for(lli i=0;i<N;i++)
	// 	{
	// 		for(lli j=0;j<N;j++)
	// 		{
	// 			cin>>Arr[i][j];
	// 		}
	// 	}
		N=3;
		memset(Arr,0,sizeof(Arr));
		Arr[0][2]=1;
		Arr[0][3]=1;
		Arr[0][0]=1;
		Arr[1][1]=1;
		Arr[2][2]=1;
		Arr[2][3]=1;
		cout<<ans()<<endl;

	//}
}