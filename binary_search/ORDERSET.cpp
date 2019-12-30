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
	set<lli> s;
	set<lli> :: iterator itr;
	set<lli> :: iterator itr2;
	while(Q--)
	{
		char type;
		lli x;
		cin>>type;
		cin>>x;
		if(type=='I')
			s.insert(x);
		if(type=='D')
			s.erase(x);
		if(type=='C')
		{
			set<lli> :: iterator itr1;
			set<lli> :: iterator itr2;
			itr2=s.lower_bound(x);
			itr1=s.upper_bound(x);
			if(itr1!=itr2)
				cout<<distance(s.begin(),itr1)-1<<endl;
			else
				cout<<distance(s.begin(),itr1)<<endl;
		}
		if(type=='K')
		{
			if(x>s.size() || x==0)
			{
				cout<<"invalid"<<endl;
			}
			else
			{
				set<lli> :: iterator itr1;
				itr1=s.begin();
			//	itr1=itr1+x-1;
				x=x-1;
				advance(itr1,x);
				cout<<*itr1<<endl;
			}
		}

		// for(itr=s.begin(); itr!=s.end(); ++itr)
		// {
		// 	cout<<*itr<<" ";
		// }
		// cout<<endl;
	}
	

		
}