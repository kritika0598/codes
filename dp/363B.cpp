#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	lli cum[N+1];
	lli Arr[N+1];
	cum[0]=0;
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		cum[i]=cum[i-1]+Arr[i];
	}
	lli mini=INT_MAX;
	lli st=0;
	for(lli i=K;i<=N;i++)
	{
		if(cum[i]-cum[i-K]<mini)
		{
			mini=cum[i]-cum[i-K];
			st=i-K+1;
		}
	}

	cout<<st<<endl;	
}