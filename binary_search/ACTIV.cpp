#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool sortby2(const pair<lli,lli> &a, const pair<lli,lli> &b)
{
	return (a.second< b.second);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli N;
		cin>>N;
		if(N=-1)
			return;
		vector<pair<lli,lli>>v1;
		vector<pair<lli,lli>>v2;
		lli Act[N];
		lli x,y;
		for(lli i=0;i<N;i++)
		{
			cin>>x>>y;
			v1.push_back(make_pair(x,y));
			v2.push_back(make_pair(x,y));
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end(),sortby2);

	}
		
}