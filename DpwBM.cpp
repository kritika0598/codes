#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli N,M,X,Y,Z;

lli adj[15][15];
bool con[15][15];


lli calc_hp()
{

	bool dp[N+1][1<<N];
	lli dp1[N+1][1<<N];

	for(lli i=0;i<(1<<N);i++)
	{
		for(lli j=0;j<N;j++)
		{
			dp[j][i]=false;
			dp1[j][i]=INT_MAX;
		}
	}

	for(lli i=0;i<N;i++)
	{
		dp[i][1<<i]=true;
		dp1[i][1<<i]=0;
	}

	for(lli i=0;i<1<<N;i++)
	{
		for(lli j=0;j<N;j++)
		{
			if(i&(1<<j))
			{
				for(lli k=0;k<N;k++)
				{
					if(k!=j && (i&(1<<k)) && con[k][j])
					{
						if(dp[k][i^(1<<j)])
						{
							dp[j][i]=true;
							dp1[j][i]=min(dp1[j][i], dp1[k][i^(1<<j)]+adj[k][j]);

							//cout<<i<<" "<<j<<" "<<" "<<k<<" "<<dp1[j][i]<<endl;
						}
					}


				}

			}


		}
	}
	lli ans=INT_MAX;
	for(lli i=0;i<N;i++)
	{
		if(dp[i][(1<<N)-1])
		{
			ans=min(ans,dp1[i][(1<<N)-1]);
			//cout<<i<<" "<<ans<<endl;
		}
	}

	return ans;

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	memset(adj,INT_MAX,sizeof(adj));
	memset(con,false,sizeof(con));
	for(lli i=0;i<15;i++)
	{
		adj[i][i]=0;
		con[i][i]=true;
	}

	cin>>N>>M;

	for(lli i=0;i<M;i++)
	{
		cin>>X>>Y>>Z;
		if(con[X-1][Y-1])
		{
			adj[X-1][Y-1]=min(adj[X-1][Y-1],Z);
			adj[Y-1][X-1]=min(adj[Y-1][X-1],Z);
		}
		else
		{
			adj[X-1][Y-1]=Z;
			adj[Y-1][X-1]=Z;
		}
		
		con[X-1][Y-1]=true;
		con[Y-1][X-1]=true;
	}

	cout<<calc_hp()<<endl;

}