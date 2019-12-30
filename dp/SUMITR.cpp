#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Arr[100][100];
lli DP[100][100];
lli N;
lli solve(lli i,lli j)
{
	if(i>=N || j>=N)
		return 0;
	if(DP[i][j]!=-1)
		return DP[i][j];
	return DP[i][j]=(max(solve(i+1,j),solve(i+1,j+1))+Arr[i][j]);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
	//	lli N;
		cin>>N;

		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<=i;j++)
			{
				cin>>Arr[i][j];
				DP[i][j]=-1;
			}


		}

		cout<<solve(0,0)<<endl;
	}
}