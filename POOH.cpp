#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,K;
	cin>>n>>K;
	lli Arr[n+1];
	Arr[0]=0;
	for(lli i=1;i<=n;i++)
	{
		cin>>Arr[i];
		Arr[i]=Arr[i-1]+Arr[i];
	}
	lli x;
	lli maxi;
	lli prev;
	lli cum[n+1];
	vector<pair<lli,lli>> v[n+1];

	lli az[n+1];
	set<lli>s;
	s.insert(0);
	s.insert(n);
	set<lli> :: iterator it;
	v[n].push_back(make_pair(Arr[n],0));
	v[0].push_back(make_pair(0,Arr[n]));
	az[0]=0;
	az[n]=Arr[n];
	lli maxi=Arr[n];
	for(lli i=0;i<K;i++)
	{
		cin>>x;
		s.insert(x);
		it = s.find(x);
		az[]
		v[*(it-1)][0].second=Arr[x]-Arr[*(it-1)];
		v[*(it)][0].first=v[*(it-1)][0].second;
		v[*(it+1)][0].first=(Arr[*(it+1)]-Arr[x]);
		v[*it][0].second= v[*(it+1)][0].first;

	}

}