#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;
	lli arr[n];
	map<lli,lli> m;
	for(lli i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	lli ans[n];
	if(n<k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	lli maxi=1;
	for(lli i=0;i<n;i++)
	{
		if(m[arr[i]]==0)
		{
			m[arr[i]]=1;
			ans[i]=1;
		}
		else
		{
			m[arr[i]]++;
			ans[i]=m[arr[i]];
			if(m[arr[i]]>k)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			if(ans[i]>maxi)
				maxi=ans[i];
		}	
	}


	if(maxi<k)
	{
		//for(lli i=n-1;i>=n-1-dif;i--)
		lli i=n-1;
		while(k!=1)
		{
			ans[i]=k;
			k--;
			i--;
			if(i<0)
			{
				cout<<"NO"<<endl;
				return 0;
			}

		}
		//ans[]
	}

	cout<<"YES"<<endl;
	for(lli i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}