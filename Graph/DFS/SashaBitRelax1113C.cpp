#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

// Returns count of subsets of arr[] with XOR value equals 
// to k. 
// Returns count of subarrays of arr with XOR 
// value equals to m 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N+1];
	lli c=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		if(Arr[i]==0)
			c++;
	}

	lli XOR[N+1];
	XOR[0]=Arr[0];
	for(lli i=1;i<N;i++)
	{
		XOR[i]=XOR[i-1]^Arr[i];
	}
	lli ans=0;
	for(lli i=0;i<N-1;i++)
	{
		for(lli j=2;j<=N;j=j+2)
		{
			if(i!=0)
			{
				if(XOR[i-1]^XOR[i+j-1]==XOR[i+j-1]^XOR[i+j-1+j])
					ans++;
			}
			else
			{
				if(XOR[i+j-1]==XOR[i+j-1]^XOR[i+j-1+j])
					ans++;
			}
			
		}
	}
}