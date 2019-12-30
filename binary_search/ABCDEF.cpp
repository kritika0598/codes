#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

map<lli,lli>lf;
map<lli,lli>ab;
map<lli,lli>ef;
map<lli,lli>ri;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	lli arr[10000];
	for(lli i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	lli a,b,c;
	lli d,e,f;
	for(lli i=0;i<n;i++)
	{
		for(lli j=0;j<n;j++)
		{
			a=arr[i];
			b=arr[j];
			f=arr[i];
			e=arr[j];
			ab[(a*b)]++;
			cout<<a*b<<" "<<ab[(a*b)]<<endl;
			ef[(f+e)]++;
			cout<<f+e<<" "<<ef[f+e]<<endl;
		}
	}
	//cout<<ab.size()<<" "<<"hello"<<endl;
	lli x=ab.size();
	for(lli i=0;i<x;i++)
	{
		for(lli j=0;j<n;j++)
		{
			lf[ab[i]+arr[j]]++;
			cout<<ab[i]+arr[j]<<"	"<<lf[ab[i]+arr[j]]<<endl;
		}
	}
	//cout<<ab.size()<<endl;
	cout<<ef.size()<<"heelo"<<endl;
	lli y=ef.size();
	for(lli i=0;i<y;i++)
	{
		for(lli j=0;j<n;j++)
		{
			if(arr[j]!=0)
				ri[ef[i]*arr[j]]++;
			cout<<ef[i]*arr[j]<<"	"<<ri[ef[i]*arr[j]]<<endl;
		}
	}
	cout<<ef.size()<<endl;
	//printCombination(arr, n, r);
	map<lli,lli> :: iterator it;
	lli count=0;
	for(it=lf.begin();it!=lf.end();++it)
	{
	//	cout<<it->first<<" "<<it->second<<" "<<ri[it->first]<<endl;
		count=count+(it->second*ri[it->first]);
		cout<<count<<endl;
	}


	cout<<count<<endl;


    return 0;
		
}



 
// Driver program to test above functions

