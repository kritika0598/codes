#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

struct bag{
	lli o; lli n; lli w;
};

lli DP[1001][80][801];

lli solve(bag Arr[], lli N, lli M, lli Q,lli i)
{
	if(i==Q)
	{
		if(N>0)
		{
			return INT_MAX;
		}
		if(M>0)
		{
			return INT_MAX;
		}
		return 0;
	}
	if(DP[i][N][M]!=-1)
	{
		return DP[i][N][M];
	}
	lli x=INT_MAX;
	if(Arr[i].o>=N && Arr[i].n>=M)
	{
		x=Arr[i].w;
		x=min(x,solve(Arr,N,M,Q,i+1));
	}
	else
		x=min(Arr[i].w+solve(Arr,N-Arr[i].o,M-Arr[i].n,Q,i+1), solve(Arr, N, M, Q,i+1));
	return DP[i][N][M]= x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli o,n;
		cin>>o>>n;
		lli q;
		cin>>q;

		bag Arr[q];
		lli x,y,z;
		for(lli i=0;i<q;i++)
		{
			cin>>x>>y>>z;
			Arr[i].o=x;
			Arr[i].n=y;
			Arr[i].w=z;
		}
		memset(DP,-1,sizeof(DP));
		cout<<solve(Arr, o,n,q,0)<<endl;
	}
}