#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

map<string,pair<string,string>> DP;

pair<string,string> solve(string s, lli N)
{
	
	if(N==1 && (s[0]=='8' || s[0]=='0'))
	{

		pair<string,string> p;
		p=make_pair("YES",s);
		return p;
	}
	else if(N==1)
	{
		return  make_pair("NO","");
	}
	if(DP.find(s)!=DP.end())
	{
		return DP[s];
	}
	if(N==2)
	{
		lli a=stoi(s);
		if(a%8==0)
		{
			return DP[s] = make_pair("YES",s);
		}
		else
		{
			pair<string,string> q,t;
			q=solve(s.substr(0,1),N-1);
			t=solve(s.substr(1),N-1);
			if(q.first=="YES")
			{
				return DP[s]=q;
			}
			if(t.first=="YES")
			{
				return DP[s]=t;
			}
			return DP[s] = q;
		}
	}
	else
	{
		string b=s.substr(N-3);
		lli a=stoi(b);
		if(a%8==0)
		{
			return DP[s]=make_pair("YES",s);
		}
		else
		{
			pair<string,string> q,r,t;
			q=solve(s.substr(0,N-1),N-1);
			r=solve(s.substr(0,N-2)+s[N-1],N-1);
			t=solve(s.substr(0,N-3)+s[N-2]+s[N-1],N-1);

			if(q.first=="YES")
			{
				return DP[s]= q;
			}
			if(r.first=="YES")
			{
				return DP[s]= r;
			}
			if(t.first=="YES")
			{
				return DP[s]= t;
			}
			return DP[s]=q;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	if(s.length()==1)
	{
		if(s[0]=='8' || s[0]=='0')
		{
			cout<<"YES"<<endl;
			cout<<s<<endl;
			return 0;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	else
	{
		pair<string,string> p=solve(s,s.length());
		if(p.first=="YES")
		{
			cout<<"YES"<<endl;
			cout<<p.second<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}

}