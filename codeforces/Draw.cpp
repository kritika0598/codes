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
	vector<pair<lli,lli>>v;
	for(lli i=0;i<N;i++)
	{
		lli x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));

	}
	lli ans=1;
	ans=ans+min(v[0].first,v[0].second);
	for(lli i=1;i<N;i++)
	{
		if(min(v[i].first,v[i].second)-max(v[i-1].first,v[i-1].second)>0)
		{
			 if(v[i-1].first==v[i-1].second)
			{
				ans=ans+min(v[i].first,v[i].second)-max(v[i-1].first,v[i-1].second);
			}
			else
			{
				ans=ans+min(v[i].first,v[i].second)-max(v[i-1].first,v[i-1].second)+1;
			}	
			
		}
		else if(min(v[i].first,v[i].second)-max(v[i-1].first,v[i-1].second)==0 && !(v[i].first==v[i-1].first && v[i].second==v[i-1].second))
		{
			ans=ans+1;
			
		}
		cout<<ans<<endl;

	}

	cout<<ans<<endl;
	
}