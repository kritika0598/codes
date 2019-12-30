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
	while(N--)
	{
		lli a,b;
		cin>>a>>b;

		lli x=a/b;
		string s;
		string q="a";
		for(lli i=0;i<b;i++)
		{
			q=static_cast<char>('a'+i);
			//cout<<q<<endl;
			for(lli j=0;j<x;j++)
			{
				s=s+q;
			}
			//cout<<s<<endl;
			//q=q+1;
		}

		q=static_cast<char>('a'+b-1);
		while(s.length()!=a)
		{
			s=s+q;
		}

		cout<<s<<endl;
	}
}