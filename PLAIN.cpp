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
		lli N=s.length();
		bool flag=false;
		for(lli i=0;i<N;i++)
		{
			if(s[i]!=9)
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			for(lli i=0;i<N+1;i++)
			{
				
			}
		}
		if(N%2!=0)
		{
			for(lli i=0;i<N/2;i++)
			{
				if(s[i]==s[N-1-i])
					continue;
				else
				{
					s[N-1-i]=s[i];
				}
			}
			s[N/2]=s[N/2]+1;
		}
		else
		{
			for(lli i=0;i<N/2-1;i++)
			{
				if(s[i]==s[N-1-i])
					continue;
				else
					s[N-1-i]=s[i];
			}
			s[N/2-1]=s[N/2-1]+1;
			s[N/2]=s[N/2-1];
		}
		
	}	
}