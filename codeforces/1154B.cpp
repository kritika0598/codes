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

	set<lli> s;
	set<lli> :: iterator itr;

	lli x;
	for(lli i=0;i<N;i++)
	{
		cin>>x;
		s.insert(x);
	}
	//sort(s.begin(),s.end());
	if(s.size()==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(s.size()==2)
	{
		lli a,b;
		vector<lli> v;
		for(itr=s.begin(); itr!=s.end();itr++)
		{
			v.push_back(*itr);
		}
		a=v[1]-v[0];
		if((a)%2==0)
			cout<<a/2<<endl;
		else
			cout<<v[1]-v[0]<<endl;
		return 0;
	}
	else
	{
		set<lli> v;
		lli prev=*s.begin();
		for(itr=s.begin();itr!=s.end();itr++)
		{
			if(itr!=s.begin())
			{
				v.insert(*itr-prev);
				prev=*itr;
			}
			
		}
		if(v.size()==1)
		{
			cout<<*v.begin()<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}