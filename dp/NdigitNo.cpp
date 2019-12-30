#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[100005][10];
lli solve(lli i, lli N, lli prev)
{
	if(i==N)
	{
		return 1;
	}
	if(DP[i][prev]!=-1)
		return DP[i][prev];
	lli x=0;
	for(lli j=prev;j<=9;j++)
	{
		x+=solve(i+1,N,j);
	}
	return DP[i][prev]=x;
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

		lli x=0;
		memset(DP,-1,sizeof(DP));
		for(lli i=0;i<=9;i++)
		{
			x+=solve(1,N,i);
		}
		cout<<x<<endl;
	}	
}