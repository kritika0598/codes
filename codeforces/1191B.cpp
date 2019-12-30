#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string>v(3);
	cin>>v[0];
	cin>>v[1];
	cin>>v[2];
	sort(v.begin(),v.end());

	map<char,vector<int>> m;
	map<char,vector<int>> :: iterator itr;

	for(int i=0;i<3;i++)
	{
		m[v[i][1]].push_back(v[i][0]-'0');
	}

	for(itr=m.begin();itr!=m.end();itr++)
	{
		vector<int> temp=itr->second;
		if(temp.size()==1)
			continue;
		else if(temp.size()==3)
		{
			int x=0;
			sort(temp.begin(),temp.end());
			if(temp[0]==temp[1])
			{
				if(temp[1]==temp[2])
				{
					cout<<0<<endl;
					return 0;
				}
				else
				{
					cout<<1<<endl;
					return 0;
				}
			}
			if(temp[1]==temp[2])
			{
				{
					cout<<1<<endl;
					return 0;
				}
			}
			if(temp[0]+1==temp[1])
			{
				if(temp[1]+1==temp[2])
				{
					cout<<0<<endl;
					return 0;
				}
				else
				{
					cout<<1<<endl;
					return 0;
				}
			}
			if(temp[1]+1==temp[2])
			{
				{
					cout<<1<<endl;
					return 0;
				}
			}
			if(temp[0]+2==temp[2] || temp[0]+2==temp[1] || temp[1]+2==temp[2])
			{
				cout<<1<<endl;
				return 0;
			}
			cout<<2<<endl;
			return 0;
		}
		else
		{
			if(temp[0]==temp[1] || temp[0]+1==temp[1] || temp[0]+2==temp[1])
			{
				cout<<1<<endl;
				return 0;
			}
			else
			{
				cout<<2<<endl;
				return 0;
			}
		}

	}
	cout<<2<<endl;	
}