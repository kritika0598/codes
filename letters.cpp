#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		lli x=s.length();
		bool flag=false;
		string arr[x];
		if(x==1)
		{
			cout<<-1<<endl;
			continue;
		}
		else
		{
			for(lli i=1;i<x;i++)
			{
				if(s[i]!=s[i-1])
				{
					flag=true;
				}
			}
			if(!flag)
			{
				cout<<-1<<endl;
			}
			else
			{
				//if(x%2==1){
					for(lli i=0;i<(x/2);i++)
					{
						if(s[i]!=s[x-1-i])
						{
							cout<<s<<endl;
							flag=false;
							break;
						}

					}
					if(flag)
					{
						sort(s.begin(),s.end());
						cout<<s<<endl;
					}
				
			}
		}
	}
		
}