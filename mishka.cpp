#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	lli b[n/2+1];
	lli a[n+1];
	for(lli i=1;i<=(n/2);i++)
	{
		cin>>b[i];
	}
	lli i=(n/2);
	//if(b[i]%2==0)
	//	{
			a[i]=b[i]/2;
			a[n-i+1]=b[i]-a[i];
	//	}
		
		lli x,y;

		a[1]=0;
		a[n]=b[1];

	for( i=2;i<=n/2;i++)
	{
		a[i]=a[i-1];
		a[n-i+1]=b[i]-a[i];
		if(a[n-i+1]>a[n-i+2])
		{
			a[i]=a[i]+a[n-i+1]-a[n-i+2];
			a[n-i+1]=a[n-i+2];
		}

	}

	for(i =1 ;i <=n;i++)
	{
		cout<<a[i]<<" ";
	}
}