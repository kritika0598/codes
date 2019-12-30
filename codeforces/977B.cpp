#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;

	string s;
	cin>>s;
	map<string,lli>m;
	lli maxi=0;
	string ans="";
	for(lli i=0;i<n-1;i++)
	{
		string a="";
		a=a+s[i]+s[i+1];
		m[a]++;
		if(m[a]>maxi)
		{

			maxi=m[a];
			ans=a;
		}	
	}

	cout<<ans<<endl;



}