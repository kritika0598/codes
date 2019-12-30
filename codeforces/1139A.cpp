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
	string s;
	cin>>s;
	lli ans=0;
	for(lli i=0;i<N;i++)
	{
		if((s[i]-'0')%2==0)
		{
			ans+=i+1;
		}
	}

	cout<<ans<<endl;
}