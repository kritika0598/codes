#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N+1];
	lli cum[N+1];
	memset(cum,0,sizeof(cum));

	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	cum[0]=1;
	lli k=0;
	for(lli i=1;i<N;i++)
	{
		if(Arr[i]==Arr[i-1])
			cum[k]++;
		else
		{
			k++;
			cum[k]++;
		}
	}
	lli mini=0;
	for(lli i=0;i<N-1;i++)
	{
		mini=max(mini,min(cum[i],cum[i+1]));
	}

	cout<<2*mini<<endl;

}