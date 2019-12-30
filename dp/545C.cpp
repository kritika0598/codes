#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[100005][2];
lli solve(lli Arr[], lli H[], lli i, lli N, lli prev,lli t)
{
	if(i>=N)
		return 0;
	if(DP[i][t]!=-1)
		return DP[i][t];
	if(Arr[i]-H[i]>prev)
	{
		if(i!=N-1 && Arr[i]+H[i]<Arr[i+1])
		{
			return DP[i][t]= max(1+solve(Arr,H,i+1,N,Arr[i],0),max(1+solve(Arr,H,i+1,N,Arr[i]+H[i],1),solve(Arr,H,i+1,N,Arr[i],0)));
		}
		else if(i==N-1)
		{
			return DP[i][t]= max(1+solve(Arr,H,i+1,N,Arr[i],0),max(1+solve(Arr,H,i+1,N,Arr[i]+H[i],1),solve(Arr,H,i+1,N,Arr[i],0)));
		}
		else if(Arr[i]+H[i]>=Arr[i+1])
		{
			return DP[i][t]= max(1+solve(Arr,H,i+1,N,Arr[i],0),solve(Arr,H,i+1,N,Arr[i],0));
		}
	}
	else
	{
		if(i!=N-1 && Arr[i]+H[i]<Arr[i+1])
		{
			return DP[i][t]= max(1+solve(Arr,H,i+1,N,Arr[i]+H[i],1),solve(Arr,H,i+1,N,Arr[i],0));
		}
		else if(i==N-1)
		{
			return DP[i][t]= max(1+solve(Arr,H,i+1,N,Arr[i]+H[i],1),solve(Arr,H,i+1,N,Arr[i],0));
		}
		else if(Arr[i]+H[i]>=Arr[i+1])
		{
			return DP[i][t]= solve(Arr,H,i+1,N,Arr[i],0);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N],H[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i]>>H[i];
	}
	memset(DP,-1,sizeof(DP));
	cout<<solve(Arr,H,0,N,INT_MIN,0)<<endl;	
}