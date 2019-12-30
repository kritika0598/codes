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
	lli Arr[N];
	map<lli,lli> m;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		m[Arr[i]]++;
		if(m[Arr[i]]>1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	bool inc=false;
	bool dec=false;
	bool flag=true;
	for(lli i=0;i<N-1;i++)
	{
		if(Arr[i+1]-Arr[i]<0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	flag=true;
	for(lli i=0;i<N-1;i++)
	{
		if(Arr[i+1]-Arr[i]>0)
		{
			flag=false;
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	flag=true;
	for(lli i=0;i<N-1;i++)
	{
		if(Arr[i+1]-Arr[i]<0)
		{
			dec=true;
		}
		if(dec && Arr[i+1]-Arr[i]>0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;


}