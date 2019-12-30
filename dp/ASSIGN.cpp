#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Arr[21][21];
lli N;
lli dp[1<<21][21];
vector <lli> v[21];

lli B=9223372036854775807;

lli ans(lli mask, lli i)
{
	
	if(mask==((1<<N)-1))
		return 1;
	if(i>=N)
		return 0;

	if(dp[mask][i]!=-1)
		return dp[mask][i];

	//lli ways=ans(mask,i+1);
	lli ways=0;
	lli z=v[i].size();

	for(lli j=0;j<z;j++)
	{
		if(!(mask & (1<<v[i][j])))
			ways+=ans(mask|(1<<v[i][j]),i+1);
	}

	return dp[mask][i]=ways;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		memset(Arr,0,sizeof(Arr));
		//memset(dp,0,sizeof(dp));
		for(lli i=0;i<21;i++)
			v[i].clear();
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				cin>>Arr[i][j];
				if(Arr[i][j])
					v[j].push_back(i);
			}
		}

		// for(lli i=0;i<N;i++)
		// {
		// 	for(lli j=0;j<N;j++)
		// 	{
		// 		if(Arr[j][i])
		// 			v[i].push_back(j);
		// 	}
		// }

		for(lli i=0;i<(1<<N);i++)
		{
			for(lli j=0;j<N;j++)
			{
				dp[i][j]=-1;
			}
		}

		cout<<ans(0,0)<<endl;

	}
}