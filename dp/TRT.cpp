#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Arr[2005];
lli N;
lli DP[2005][2005];
lli foo(lli start,lli end)
{
	lli a=start+N-end;
	if(start==end)
		return a*max(Arr[start],Arr[end]);
	if(DP[start][end]!=-1)
		return  DP[start][end];
	return DP[start][end] = max(a*Arr[start]+foo(start+1,end), a*Arr[end]+foo(start,end-1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	for(lli i=0;i<N;i++)
	{
		for(lli j=0;j<N;j++)
		{
			DP[i][j]=-1;
		}
	}
	for(lli i=0;i<N;i++)
	{
		DP[i][i]=Arr[i];
	}
	lli x=foo(0,N-1);
	cout<<DP[0][N-1]<<endl;
//	cout<<x<<endl;
}