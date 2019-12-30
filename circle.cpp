#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<lli> v;
	lli N;
	cin>>N;
	for(lli i=1;i<=N;i++)
	{
		v.push_back(i);
	}
	vector<lli>::iterator it; 
	lli i=0;
	it=v.begin();
	while(v.size()!=1)
	{
		cout<<v[i]<<endl;
		
		if(it==v.end()-1)
		{
			it=v.begin();
			i=0;
		}	
		else
		{
			it=it+1;
			i=i+1;

		}	
		if(i==v.size()-1)
		{
			v.erase(it);
			it=v.begin();
			i=0;
		}
		else
		{
			v.erase(it);
		}
		
	}
	cout<<v[0]<<endl;
		
}