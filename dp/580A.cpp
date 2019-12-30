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
	lli LIS[N];
	lli maxi=1;
	lli temp=1;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}	
	for(lli i=1;i<N;i++)
	{
		if(Arr[i]>=Arr[i-1])
		{
			temp++;
			if(temp>maxi)
				maxi=temp;
		}
		else
		{
			temp=1;
		}
	}
	cout<<maxi<<endl;

}