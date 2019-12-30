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

	lli sum=0;
	lli i=0;
	while(i!=n)
	{
		sum=sum+(Arr[i+1]-Arr[i]);
		i=i+2;
		//cout<<sum<<endl;
	}
	cout<<sum<<endl;

		
}
