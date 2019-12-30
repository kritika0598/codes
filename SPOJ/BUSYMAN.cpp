#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--)
	{
		lli N;
		cin>>N;
		vector<pair<lli,lli>> v;
		lli x,y;
		for(lli i=0;i<N;i++)
		{
			cin>>x>>y;
			v.push_back(make_pair(y,x));
		}

		sort(v.begin(),v.end());

		lli cnt=1;
		lli z=v[0].first;
		for(lli i=1;i<N;i++)
		{
			if(v[i].second>=z)
			{
				cnt++;
				z=v[i].first;
			}	

		}

		cout<<cnt<<endl;
	}
}