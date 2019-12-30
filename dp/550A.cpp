#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string st;
	cin>>st;
	lli N=st.length();
	vector<lli> s;
	vector<lli> e;
	for(lli i=0;i<N-1;i++)
	{
		if(st[i]=='A' && st[i+1]=='B')
		{
			s.push_back(i);
			e.push_back(i+1);
		}
	}

	if(s.size()==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(lli i=0;i<N-1;i++)
	{
		if(st[i]=='B' && st[i+1]=='A')
		{
			if(find(e.begin(),e.end(),i)==e.end() && find(s.begin(),s.end(),i+1)==s.end())
			{
				cout<<"YES"<<endl;
				return 0;
			}
			if(s.size()>=2 && e.size()>=2)
			{
				if(s.size()==2)
				{
					if(find(e.begin(),e.end(),i)==e.end() || find(s.begin(),s.end(),i+1)==s.end())
					{
						cout<<"YES"<<endl;
						return 0;
					}
					// else
					// {
					// 	cout<<"NO"<<endl;
					// 	return 0;
					// }
				}
				else
				{
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO"<<endl;	
}