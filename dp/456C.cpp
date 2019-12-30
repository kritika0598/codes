#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli DP[100005];
lli freq[100005];
lli solve(lli i)
{
	if(i==1)
		return DP[i]=freq[i];
	else if(i==0)
		return DP[i]=0;
	if(DP[i]!=-1)
		return DP[i];
	return DP[i]=max(solve(i-1),solve(i-2)+freq[i]*i);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N+1];
	memset(freq,0,sizeof(freq));
	lli maxi=0;
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		if(Arr[i]>maxi)
			maxi=Arr[i];
		freq[Arr[i]]++;
	}
	memset(DP,-1,sizeof(DP));
	cout<<solve(maxi)<<endl;	
}