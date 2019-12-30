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
		string s;
		cin>>s;

		lli ans=0;
		lli l=0,r=-1;

		for(lli i=0;i<s.length();i++)
		{
			if(s[i]=='A'|| s[i]=='a' || s[i]=='B' || s[i]=='b' || s[i]=='c'|| s[i]=='C')
			{
				r=i;
			}
			else
			{
				ans+=((r-l+1)*(r-l+2)/2);
				l=i+1;
				r=i+1;
			}
		}
		if(r==s.length()-1)
		{
			ans+=((r-l+1)*(r-l+2)/2);
		}

		cout<<ans<<endl;

	}
}