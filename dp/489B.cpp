#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[105][105];

lli solve(lli Arr[] ,lli Brr[] ,lli N,lli M,lli i,lli j)
{
	if(i>=N || j>=M)
		return DP[i][j]=0;
	if(DP[i][j]!=-1)
		return DP[i][j];
	if(abs(Arr[i]-Brr[j])==1 || abs(Arr[i]-Brr[j])==0)
	{
		return DP[i][j]=1+solve(Arr,Brr,N,M,i+1,j+1);
	}
	else
		return DP[i][j] = max(solve(Arr,Brr,N,M,i+1,j),solve(Arr,Brr,N,M,i,j+1));
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
	lli M;
	cin>>M;
	lli Brr[M];
	for(lli i=0;i<M;i++)
	{
		cin>>Brr[i];
	}

	sort(Arr,Arr+N);
	sort(Brr,Brr+M);
	memset(DP,-1,sizeof(DP));
	cout<<solve(Arr,Brr,N,M,0,0)<<endl;
}