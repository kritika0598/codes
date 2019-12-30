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
	lli Arr[N+1];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	sort(Arr,Arr+N);
	lli maxi=0;
	for(lli i=0;i<N;i++)
	{
		lli x=upper_bound(Arr,Arr+N,Arr[i]+5)-Arr;
		//cout<<x-1<<" "<<Arr[x-1]<<endl;
		//if(Arr[x-1]>Arr[i]+5)
		{
			if((x-1)-i+1>maxi)
				maxi=x-i;
		}
	}

	cout<<maxi<<endl;



}