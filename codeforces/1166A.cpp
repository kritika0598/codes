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
	map<char,lli> m;
	string s;
	int maxi=0;
	for(lli i=0;i<N;i++)
	{
		cin>>s;
		m[s[0]]++;
		if(m[s[0]]>maxi)
			maxi=m[s[0]];
	}
	lli ans=0;
	if(maxi%2==0)
	{
		ans=(maxi/2);
		ans=ans*(ans-1);
	}
	else
	{
		ans=(maxi/2+1);
		ans=(ans*(ans-1)/2);
		lli x=maxi/2;
		ans+=(x*(x-1))/2;
	}

	cout<<ans<<endl;


}