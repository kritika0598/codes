#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli cmp(string a, string b)
{
	lli ans=0;
	for(lli i=0;i<a.length();i++)
	{
		if(a[i]!=b[i])
		{
			ans++;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2;
	cin>>s1>>s2;
	lli n=s1.length();
	lli m=s2.length();
	lli ans=0;	
	for(lli i=0;i<=n-m;i++)
	{
		string a=s1.substr(i,m);
		if(cmp(a,s2)%2==0)
				ans++;
	}

	cout<<ans<<endl;
}