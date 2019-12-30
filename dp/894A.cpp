#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	lli Arr[s.length()];
	lli pre[s.length()];
	for(lli i=0;i<s.length();i++)
	{
		if(i==0)
		{
			if(s[i]=='Q')
			{
				pre[i]=1;
			}
			else
			{
				pre[i]=0;
			}
		}
		else
		{
			if(s[i]=='Q')
			{
				pre[i]=pre[i-1]+1;
			}
			else
			{
				pre[i]=pre[i-1];
			}
		}
	}
	lli suf[s.length()];
	for(lli i=s.length()-1;i>=0;i--)
	{
		if(i==s.length()-1)
		{
			if(s[i]=='Q')
			{
				suf[i]=1;
			}
			else
			{
				suf[i]=0;
			}
		}
		else
		{
			if(s[i]=='Q')
			{
				suf[i]=suf[i+1]+1;
			}
			else
			{
				suf[i]=suf[i+1];
			}
		}
	}

	lli ans=0;
	for(lli i=1;i<s.length()-1;i++)
	{
		if(s[i]=='A')
		{
			ans+=(pre[i-1]*suf[i+1]);
		}
	}

	cout<<ans<<endl;
}