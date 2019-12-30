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
	lli a[N];
	vector<lli> v;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		a[i]=Arr[i];
	}
	lli count1=0;
	for(lli i=1;i<N-1;i++)
	{
		if(Arr[i-1]==1 && Arr[i]==0 && Arr[i+1]==1)
		{
			count1++;
			v.push_back(i);
		}
	}
	lli ans=0;
	for(lli i=2;i<N-2;i++)
	{
		if(a[i]==1 && a[i-1]==0 && a[i+1]==0 && a[i+2]==1 && a[i-2]==1)
		{
			a[i]=0;
			ans++;
		}
	}
	for(lli i=1;i<N-1;i++)
	{
		if(a[i]==0 && a[i-1]==1 && a[i+1]==1 )
		{
			ans++;
			a[i+1]=0;
		}
	}

	if(count1==0)
	{
		cout<<0<<endl;
	}
	else
	{

		cout<<ans<<endl;
	}
}