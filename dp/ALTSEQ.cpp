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
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	lli lcs[N];
	for(lli i=0;i<N;i++)
	{
		lcs[i]=1;
	}
	lli maxi=1;
	for(lli i=1;i<N;i++)
	{
		for(lli j=0;j<i;j++)
		{
			if(abs(Arr[j])<abs(Arr[i]) && Arr[j]*Arr[i]<0)
			{
				if(lcs[i]<1+lcs[j])
				{
					lcs[i]=1+lcs[j];
				}
				if(lcs[i]>maxi)
					maxi=lcs[i];
			}
		}
	}	

	cout<<maxi<<endl;
}