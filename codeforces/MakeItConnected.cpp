#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,q;
	cin>>n>>q;
	lli Arr[n];
	cin>>Arr[0];
	lli mini=Arr[0];
	for(lli i=1;i<n;i++)
	{
		cin>>Arr[i];
		if(Arr[i]<mini)
			mini=Arr[i];
	}

	//sort(Arr,Arr+n);
	lli sum=0;
	for(lli i=0;i<n;i++)
	{
		sum=sum+Arr[i]+mini;
	}
	sum=sum-2*mini;
//	cout<<sum<<endl;
	lli x,y,val;
	for(lli i=0;i<q;i++)
	{
		cin>>x>>y>>val;
		if(val<max(Arr[x-1]+mini,Arr[y-1]+mini))
			sum=sum-max(Arr[x-1]+mini,Arr[y-1]+mini)+val;
	}
	cout<<sum<<endl;
}