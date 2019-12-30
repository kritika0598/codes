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
	lli arr[n+1];
	lli a[n+1];
	map<lli,lli>m;
	for(lli i=1;i<=n;i++)
	{
		cin>>arr[i];
		m[arr[i]]=i;
		a[i]=i;
	}


	lli b[n+1];
	lli last=0;
	for(lli i=0;i<n;i++)
	{
		cin>>b[i];
		lli x=m[b[i]];
		b[i]=a[x];
		if(x<last)
			b[i]=0;
		if(x>last)
		{
			b[i]=a[x]-last;
			last=x;
		}
		cout<<b[i]<<" ";		

	}
	cout<<endl;

		
}