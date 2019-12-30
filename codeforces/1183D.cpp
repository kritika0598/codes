#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		map<lli,lli> m;
		lli x;
		for(lli i=0;i<N;i++)
		{
			cin>>x;
			m[x]++;
		}
		vector<lli> v;
		map<lli,lli> :: iterator itr;
		for(itr=m.begin();itr!=m.end();itr++)
		{
			v.push_back(itr->second);
		}
		sort(v.begin(),v.end());
		if(v.size()==1)
		{
			cout<<v[0]<<endl;
			continue;
		}
		lli ans=v[v.size()-1];
		lli prev=v[v.size()-1];
		for(lli i=v.size()-2;i>=0;i--)
		{
			//cout<<ans<<" "<<v[i]<<" "<<prev<<endl;
			if(prev==0)
				break;
			ans+=min(v[i],prev-1);
			prev=min(v[i],prev-1);
		//	cout<<ans<<" "<<v[i]<<" "<<prev<<endl;
			if(prev==1)
				break;
		}
		cout<<ans<<endl;

	}
}