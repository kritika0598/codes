#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,H,M;
	cin>>N>>H>>M;

	lli Arr[N+1];

	lli sum=0;
	lli maxi=pow(H,2);
	for(lli i=01;i<=N;i++)
	{
		Arr[i]=maxi;
	}

	for(lli i=0;i<M;i++)
	{
		lli l,r,x,c;
		cin>>l>>r>>x>>c;
		lli s=0;
		for(lli j=l;j<=r;j++)
		{
			s+=Arr[i];
		}

		if(s<((r-l+1)*(x*x)))
		{
			
		}
	}

}