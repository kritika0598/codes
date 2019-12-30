#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	map<lli,vector<pair<char,string>>> m;
	map<lli,vector<pair<char,string>>> ::iterator itr;

	string s;
	while(N--)
	{
		cin>>s;
		lli a=0;
		char last;
		for(lli i=0;i<s.length();i++)
		{
			if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
			{
				a++;
				last=s[i];
			}
		}

		m[a].push_back({last,s});
	}

	
	vector<pair<lli,pair<string,string>>> v;
	vector<pair<lli,string>> alone;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		//cout<<(itr->first)<<endl;
		sort(m[(itr->first)].begin(),m[(itr->first)].end());
		for(lli j=0;j<m[(itr->first)].size()-1;j++)
		{
			if(m[(itr->first)][j].first==m[(itr->first)][j+1].first)
			{
				v.push_back(make_pair((itr->first),make_pair(m[(itr->first)][j].second,m[(itr->first)][j+1].second)));
				j++;
			}
			else
			{
				alone.push_back({(itr->first),m[(itr->first)][j].second});
				if(j==m[(itr->first)].size()-2)
				{
					alone.push_back({(itr->first),m[(itr->first)][j+1].second});
				}
			}
		}
	}

	// for(lli i=0;i<v.size();i++)
	// {
	// 	cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
	// }
	// for(lli i=0;i<alone.size();i++)
	// {
	// 	cout<<alone[i].first<<" "<<alone[i].second<<endl;
	// }

	vector<string> z[100001]; 
	lli x=0;
	if(v.size()==0)
	{
		cout<<0<<endl;
		return 0;
	}
//	cout<<"Hello"<<endl;
	if(alone.size()!=0)
	{
		for(lli i=0;i<alone.size()-1;i++)
		{
			if(alone[i].first==alone[i+1].first)
			{
				z[x].push_back(alone[i].second);
			sam	z[x].push_back(alone[i+1].second);
				i++;
				x++;
			}

		}
	}
	
	lli p=0;
	//cout<<x<<endl;
	if(v.size()<=x)
	{
		while(p!=x)
		{
			z[p].push_back(v[p].second.first);
			z[p].push_back(v[p].second.second);
			p++;
		}
	}
	else
	{
		if(x!=0)
		{
			while(p!=x)
			{
				z[p].push_back(v[p].second.first);
				z[p].push_back(v[p].second.second);
				p++;
			}
		}
		
		lli q=p;
		if(v.size()-q>=2)
		{
			z[p].push_back(v[q].second.first);
			z[p].push_back(v[q].second.second);
			q++;
			z[p].push_back(v[q].second.first);
			z[p].push_back(v[q].second.second);
			q++;
			p++;
		}
	}
	cout<<p<<endl;
	for(lli i=0;i<p;i++)
	{
		//for(lli j=0;j<2;j++)
		{
			cout<<z[i][0]<<" "<<z[i][2];
		}
		cout<<endl;
	//	for(lli j=2;j<4;j++)
		{
			cout<<z[i][1]<<" "<<z[i][3];
		}
		cout<<endl;
	}


}