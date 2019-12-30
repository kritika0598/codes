#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli DP[105][2][2];


lli solve(lli Arr[], lli i, lli N, lli g, lli c)
{
	if(i>=N)
		return 0;
	if(DP[i][g][c]!=-1)
		return DP[i][g][c];
	if(Arr[i]==0)
	{
		return DP[i][g][c]= 1+solve(Arr,i+1,N,0,0);
	}
	
	if(Arr[i]==1)
	{
		if(c==0)
		{
			return DP[i][g][c]=min(1+solve(Arr,i+1,N,0,0), solve(Arr,i+1,N,0,1));
		}
		else
		{
			return DP[i][g][c]= 1+solve(Arr,i+1,N,0,0);
		}
	}
	if(Arr[i]==2)
	{
		if(g==0)
		{
			return DP[i][g][c]= min(1+solve(Arr,i+1,N,0,0), solve(Arr,i+1,N,1,0));
		}
		else
		{
			return DP[i][g][c]=1+solve(Arr,i+1,N,0,0);
		}
	}
	if(Arr[i]==3)
	{
		if(c==0 && g==0)
		{
			return DP[i][g][c]= min(1+solve(Arr,i+1,N,0,0), min(solve(Arr,i+1,N,1,0), solve(Arr,i+1,N,0,1)));
		}
		if(c==0)
		{
			return DP[i][g][c]= min(1+solve(Arr,i+1,N,0,0),solve(Arr,i+1,N,0,1));
		}
		if(g==0)
		{
			return DP[i][g][c]= min(1+solve(Arr,i+1,N,0,0),solve(Arr,i+1,N,1,0));
		}
		else
		{
			return DP[i][g][c]= 1+solve(Arr,i+1,N,0,0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	memset(DP,-1,sizeof(DP));
	cout<<solve(Arr,0,N,0,0)<<endl;	
}