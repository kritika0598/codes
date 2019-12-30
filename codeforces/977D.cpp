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
	vector<pair<lli,lli>> v;
	lli x;
	for(lli i=0;i<N;i++)
	{
		lli c;
		cin>>c;
		x=c;
		lli t=0;
		while(x%3==0)
		{
			t++;
			x/=3;
		}

		v.push_back(make_pair(-t,c));
	}

	sort(v.begin(),v.end());

	for(lli i=0;i<N;i++)
	{
		cout<<v[i].second<<" ";
	}
	cout<<endl;
}