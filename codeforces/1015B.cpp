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
	string s,t;
	cin>>s>>t;
	map<char,int> s1;
	map<char,int> t1;

	for(lli i=0;i<N;i++)
	{
		s1[s[i]]++;
		t1[t[i]]++;
	}

	map<char,int> :: iterator itr;
	for(itr=s1.begin();itr!=s1.end();itr++)
	{
		if(t1[itr->first]!=itr->second)
		{
			cout<<-1<<endl;
			return 0;
		}
	}

	vector<lli> ans;
	lli cnt=0;
	lli i=0;
	while(s!=t)
	{
		if(s[i]==t[i])
		{
			i++;
		}
		else
		{
			if(i<=N-2)
			{
				char temp=s[i];
				s[i]=s[i+1];
				s[i+1]=temp;
				ans.push_back(i+1);
				i++;
				cnt++;
			}
			else
			{
				char temp=s[i];
				s[i]=s[i-1];
				s[i-1]=temp;
				ans.push_back(i+1);
				i=0;
				cnt++;
			}

		}
		if(cnt>10000)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(i>=N)
			i=0;
		//cout<<i<<endl;
	}

	cout<<ans.size()<<endl;
	for(lli i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}