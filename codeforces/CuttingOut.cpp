#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	lli Arr[N];
	map<lli,lli> m;
	map<lli,lli> :: iterator it;
	map<lli,lli> :: iterator it1;
	lli maxi=0;
	lli val=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		m[Arr[i]]++;
		if(m[Arr[i]]>maxi)
		{
			maxi=m[Arr[i]];
			val=Arr[i];
		}	
	}
	lli x=max(N/M,maxi);
	if(M==1)
	{
		cout<<val<<endl;
		return 0;
	}
	//sort(m.begin(),m.end());
	map<lli,lli> mc;
	bool flag=false;
	for(lli i=x;i>=1;i--)
	{
		lli c=0;
		for(it=m.begin();it!=m.end();++it)
		{
			c=c+(it->second/i);
			mc[it->first]=(it->second/i);
			if(c>=M)
			{
				flag=true;
				break;
			}
		}
		if(flag)
			break;
		else
		{
			for(it1=mc.begin();it1!=mc.end();it1++)
			{
				it1->second=0;
			}

		}
	}
	lli c=0;


	for(it=mc.begin();it!=mc.end();it++)
	{
		for(lli i=0;i<it->second;i++)
		{
			cout<<it->first<<" ";
			c++;
			if(c==M)
				return 0;
		}
	}


}