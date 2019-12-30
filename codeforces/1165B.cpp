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
	lli Arr[n];
	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
	}		

	sort(Arr,Arr+n);
	lli count=0;
	lli s=1;
	for(lli i=0;i<n;i++)
	{
		if(Arr[i]>=s)
		{
			count++;
			s++;
		}
	}

	cout<<count<<endl;
}