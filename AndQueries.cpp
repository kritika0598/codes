#include<iostream>
#include<bits/stdc++.h>
#define 1000000007 MOD
using namespace std;
typedef long long int lli;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	lli Arr[N+1];
	lli X[256][N+1];
	memset(X,0,sizeof(X));
	//vector<lli>v[256];
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		for(lli j=0;j<255;j++)
		{
			X[j][i]=X[j][i-1];
		}
		X[Arr[i]][i]=X[Arr[i]][i-1]+1;
	}

	lli M;
	cin>>M;
	while(M--)
	{
		lli l,r,x;
		cin>>l>>r>>x;
		lli v=X[x][r]-X[x][l-1];
		
	}

		
}