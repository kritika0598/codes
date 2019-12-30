#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
map<pair<lli,lli>,lli> m;
lli solve(lli Arr[], lli i, lli K, lli N)
{
	if(K==1)
	{
		lli mini=Arr[i];
		lli maxi=Arr[N-1];
		return maxi-mini;
	}
	if(m[{i,K}]!=0)
	{
		return m[{i,K}];
	}
	lli mini=Arr[i];
	lli maxi=Arr[i];
	lli x=INT_MAX;
	for(lli j=i;j<=N-K;j++)
	{
		x=min(x,Arr[j]-Arr[i]+solve(Arr,j+1,K-1,N));
	}
	m[{i,K}]=x;
	return x;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	if(N==K)
	{
		cout<<0<<endl;
		return 0;
	}
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	// lli ans=INT_MAX;
	// lli i=0;
	// lli len=N-K+1;
	// while(i+len<=N)
	// {
	// 	lli mini=Arr[i];
	// 	lli maxi=Arr[i];
	// 	for(lli j=i;j<i+len;j++)
	// 	{
	// 		if(Arr[j]>maxi)
	// 			maxi=Arr[j];
	// 		if(Arr[j]<mini)
	// 			mini=Arr[j];
	// 	}
	// 	ans=min(ans,maxi-mini);
	// 	i++;
	// }
	// cout<<ans<<endl;
	// lli ans=INT_MAX;
	// lli X=N-K+1;
	// K=(N-(K-1));
	// for(lli i=0;i<=N-K;i++)
	// {	
	// 	lli mini=Arr[i];
	// 	lli maxi=Arr[i];
	// 	//cout<<i<<endl;
	// 	for(lli j=i;j<i+X;j++)
	// 	{
	// 		//cout<<j<<" ";
	// 		if(Arr[j]>maxi)
	// 			maxi=Arr[j];
	// 		if(Arr[j]<mini)
	// 			mini=Arr[j];
	// 	}
	// 	//cout<<endl;
	// 	ans=min(ans,maxi-mini);
	// }

	cout<<solve(Arr,0,K,N)<<endl;
}