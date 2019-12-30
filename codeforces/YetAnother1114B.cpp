#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,k;
	cin>>n>>m>>k;
	lli Arr[n];
	vector<pair<lli,lli>> v;
	vector<pair<lli,lli>>v1;
	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
		v.push_back(make_pair(Arr[i],i+1));
	}

	sort(v.begin(),v.end());
	lli ans=0;
	for(lli i=n-1;i>=(n-m*k);i--)
	{
		v1.push_back(make_pair(v[i].second,v[i].first));
		ans=ans+v[i].first;
	}

	sort(v1.begin(),v1.end());

	cout<<ans<<endl;

	for(lli i=1;i<k;i++)
	{
	//	ans=ans+v1[i-1].second+v1[i].second;
		cout<<v1[i*m-1].first<<" ";	
	}
	return 0;

}