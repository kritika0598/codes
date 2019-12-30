#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	map<string,lli> m;
	string s;
	lli x;
	for(lli i=0;i<N;i++)
	{
		cin>>s>>x;
		m[s]+=x;
	}
    vector<pair<string,lli>>vec;

	for(auto x=m.begin();x!=m.end();x++)
		vec.push_back(*x);
	sort(vec.begin(),vec.end(),[](pair<string,lli>elem1,pair<string,lli>elem2){return elem1.second > elem2.second;});
	lli ans=0;
	lli b=0;
	for(auto x:vec)
	{
		ans=ans+x.second;
		b++;
		if(b==K)
			break;
	}

	cout<<ans<<endl;


}