#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m;
	cin>>n>>m;
	lli AO[n];
	lli AE[n];
	lli l=0,p=0;
	for(lli i=0;i<n;i++)
	{
		lli x;
		cin>>x;
		if(x%2==0)
		{
			AE[l]=x;
			l++;
		}
		else
		{
			AO[p]=x;
			p++;
		}
	}
	lli j=0,k=0;
	lli BE[m];
	lli BO[m];
	for(lli i=0;i<m;i++)
	{
		lli x;
		cin>>x;
		if(x%2==0)
		{
			BE[j]=x;
			j++;
		}
		else
		{
			BO[k]=x;
			k++;
		}
	}
	lli ans=0;
	ans=min(l,k);
	ans+=min(j,p);

	cout<<ans<<endl;		
}