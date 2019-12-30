#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[500005][3];
lli solve(lli Arr[], lli sum, lli cursum,lli j,lli k, lli N)
{
	if(j>=N)
		return 0;
	cursum+=Arr[j];
	if(sum==cursum && k==3)
	{
		return 1;
	}
	if(DP[j][k]!=-1)
		return DP[j][k];
	if(sum==cursum)
	{
		k++;
		return DP[j][k-1]=solve(Arr,sum,0,j+1,k,N) + solve(Arr,sum,cursum,j+1,k-1,N);
	}
	else
	{
		return DP[j][k]=solve(Arr,sum,cursum,j+1,k,N);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N];
	memset(DP,-1,sizeof(DP));
	lli sum=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		sum+=Arr[i];
	}
	if(N<3)
	{
		cout<<0<<endl;
	}
	else if(sum%3!=0)
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<solve(Arr,sum/3,0,0,1,N)<<endl;
	}
}