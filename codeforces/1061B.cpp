#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m;
	cin>>n>>m;
	lli Arr[n+1];
	lli sum=0;

	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
		sum+=Arr[i];
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	sort(Arr,Arr+n);
	lli b=Arr[n-1];
	lli count=0;

	for(lli i=n-1;i>=1;i--)
	{
		count+=Arr[i]-Arr[i-1];
		if(Arr[i]-Arr[i-1]==0)
		{
			count+=1;
			b-=1;
		}
		b-=Arr[i]-Arr[i-1];
	}
	if(b>0)
		count=count+b;
	else
		count++;
	cout<<sum-count<<endl;
}