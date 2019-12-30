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
	lli Arr[2*N];
	lli cum[2*N];
	lli s=0;
	for(lli i=0;i<2*N;i++)
	{
		cin>>Arr[i];
		if(i==0)
		{
			cum[i]=Arr[i];
		}
		else
		{
			cum[i]=cum[i-1]+Arr[i];
		}
	}

	if(cum[2*N-1]-cum[N-1]!=cum[N-1])
	{
		for(lli i=0;i<2*N;i++)
		{
			cout<<Arr[i]<<" ";

		}
		return 0;
	}
	for(lli i=0;i<2*N;i++)
	{
		if(i<N)
		{
			if(cum[N-1]-cum[i]+cum[N-1+i+1]!=cum[2*N-1]-cum[N-1+i+1]+cum[i])
			{
				for(lli j=i+1;j<2*N;j++)
				{
					cout<<Arr[j]<<" ";
				}
				for(lli j=0;j<=i;j++)
				{
					cout<<Arr[j]<<" ";
				}
				return 0;
			}
		}
		else
		{
			if(cum[2*N-1]-cum[i-1])
		}
		
	}


}