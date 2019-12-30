#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli DP[2][100005];
lli solve(lli A[], lli B[], lli i, lli j,lli N)
{
	if(j>=N)
		return 0;
	if(DP[i][j]!=-1)
		return DP[i][j];
	lli x=0;
	if(i==0)
	{
		x=max(A[j]+solve(A,B,1,j+1,N), A[j]+solve(A,B,1,j+2,N));
	}
	if(i==1)
	{
		x=max(B[j]+solve(A,B,0,j+1,N), B[j]+solve(A,B,0,j+2,N));
	}
	//cout<<x<<endl;
	return DP[i][j]=x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli A[N],B[N];
	for(lli i=0;i<N;i++)
	{
		cin>>A[i];
	}
	for(lli i=0;i<N;i++)
	{
		cin>>B[i];
	}

	lli ans=0;
	memset(DP,-1,sizeof(DP));
	ans=max(solve(A,B,0,0,N),solve(A,B,1,0,N));
	cout<<ans<<endl;
}