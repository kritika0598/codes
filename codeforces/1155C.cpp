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

	lli Arr[n];
	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
	}

	lli B[m];
	for(lli i=0;i<m;i++)
	{
		cin>>B[i];
	}

	lli dif[n];
	lli g;
	for(lli i=0;i<n-1;i++)
	{
		dif[i]=Arr[i+1]-Arr[i];
	}
	g=dif[0];	
	for(lli i=1;i<n-1;i++)
	{
		g=__gcd(g,dif[i]);
	}
	bool flag=true;
	for(lli i=0;i<m;i++)
	{
		if(g%B[i]==0)
		{
			cout<<"YES"<<endl;
			cout<<Arr[0]<<" "<<i+1<<endl;
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<"NO"<<endl;
	}

}