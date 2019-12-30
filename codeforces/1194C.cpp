#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli Q;
	cin>>Q;
	while(Q--)
	{
		string s,t,p;
		cin>>s>>t>>p;
		map<char,lli> a,b,c;

		for(lli i=0;i<s.length();i++)
		{
			a[s[i]]++;
		}
		for(lli i=0;i<p.length();i++)
		{
			b[p[i]]++;
		}
		for(lli i=0;i<t.length();i++)
		{
			c[t[i]]++;
		}

		bool flag=true;
		lli j=0;
		for(lli i=0;i<t.length();i++)
		{
			if(j<s.length() && t[i]==s[j])
			{
				a[s[j]]--;
				j++;
			}
			else
			{
				if(b[t[i]]==0)
				{
					cout<<"NO"<<endl;
					flag=false;
					break;
				}
				else
				{
					b[t[i]]--;
				}
			}
		}

		if(flag)
		{
			if(j<s.length())
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
			}
		}
	}
}