#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;
	lli Arr[n+1];

	
	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
	}
	sort(Arr,Arr+n);
	if(k==0)
	{
		if(Arr[0]==1)
			cout<<-1<<endl;
		else
			cout<<1<<endl;
		return 0;
	}
	if(n==1 && k==1)
	{
		cout<<Arr[0]<<endl;
		return 0;
	}
	

	if(n==k)
	{
		cout<<Arr[n-1]<<endl;
		return 0;
	}
	if(Arr[k-1]==Arr[k])
		cout<<-1<<endl;
	else
	{
		cout<<Arr[k-1]<<endl;
	}
}