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
		lli N;
		cin>>N;
		string s;
		cin>>s;
		if(N<11)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			if(find(s.begin(),s.end(),'8')!=s.end())
			{
				lli k=0;
				for(lli i=0;i<N;i++)
				{
					if(s[i]=='8')
					{
						k=i;
						break;
					}
				}
				if(N-k>=11)
				{
					cout<<"YES"<<endl;
				}
				else
				{
					cout<<"NO"<<endl;
				}
			}
			else
			{
				cout<<"NO"<<endl;
			}
			
		}
	}
}