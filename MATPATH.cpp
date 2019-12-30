#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[501][501];
lli DP1[101][101];
lli DP2[101][101];
lli solve1(lli N, lli i, lli j)
{
	if(i==0 && j==0)
	{
		return Arr[i][j];
	}
	if(i==j)
	{
		return INT_MAX;
	}

	if(i<0 || j<0)
	{
		return INT_MAX;
	}
	if(DP2[i][j]!=-1)
		return DP2[i][j];
	lli x=INT_MAX;
	{
		x=min(x,Arr[i][j]+solve1(N,i-1,j));
	}
	{
		x=min(x,Arr[i][j]+solve1(N,i,j-1));
	}

	return DP2[i][j]=x;
}

lli solve(lli N, lli i, lli j)
{
	if(i==N-1 && j==N-1)
	{
		return Arr[i][j];
	}
	if(i==j)
	{
		return INT_MAX;
	}

	if(i>=N || j>=N)
	{
		return INT_MAX;
	}
	if(DP1[i][j]!=-1)
		return DP1[i][j];

	lli x=INT_MAX;
	{
		x=min(x,Arr[i][j]+solve(N,i+1,j));
	}
	{
		x=min(x,Arr[i][j]+solve(N,i,j+1));
	}
	return DP1[i][j]=x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				cin>>Arr[i][j];
			}
		}
		memset(DP1,-1,sizeof(DP1));
		memset(DP2,-1,sizeof(DP2));
		cout<<Arr[0][0]+solve(N,0,1)+solve1(N,N-1,N-2)<<endl;
	}
}