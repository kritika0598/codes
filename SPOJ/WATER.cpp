#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;


	while(T--)
	{
		lli m,n;
		cin>>n>>m;
		lli root[n+1][m+1][2];
		lli Arr[n+1][m+1];

		for(lli i=1;i<=n;i++)
		{
			for(lli j=1;j<=m;j++)
			{
				cin>>Arr[i][j];
				root[i][j][0]=i;
				root[i][j][1]=j;
			}
		}

		for(lli j=1;j<=m;j++)
		{
			if(Arr[2][j]==Arr[1][j])
			{
				root[2][j][0]=1;
				root[2][j][1]=j;
			}	

		}
		for(lli j=1;j<=m;j++)
		{
			if(Arr[n-1][j]==Arr[n][j])
			{
				root[n-1][j][0]=n;
				root[n-1][j][1]=j;
			}	

		}

		for(lli i=1;i<=n;i++)
		{
			if(Arr[i][2]==Arr[i][1])
			{
				root[i][2][0]=i;
				root[i][2][1]=1;
			}
		}

		for(lli i=1;i<=n;i++)
		{
			if(Arr[i][m-1]==Arr[i][m])
			{
				root[i][m-1][0]=i;
				root[i][m-1][1]=m;
			}
		}


		for(lli i=3;j<=n-2;i++)
		{
			for(lli j=3;j<=m-2;j++)
			{
				if(Arr[i][j]==Arr[i+1][j+1])
				{
					root[i][j][0]=root[i+1][j+1][0];
					root[i][j][1]=root[i+1][j+1][1];
				}
			}
		}


		for(lli i=2;i<=n-1;i++)
		{
			for(lli j=2;j<=m-1;j++)
			{

			}
		}
	}
}