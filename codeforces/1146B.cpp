#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s="";
	string s1="";
	string t;

	cin>>t;

	lli ind=-1;
	bool flag=true;
	for(lli i=0;i<t.length();i++)
	{
		if(t[i]=='a')
			ind=i;
		else
			flag=false;
	}

	if(flag)
	{
		cout<<t<<endl;
		return 0;

	}
	flag=true;
	if(ind==-1)
	{
		if(t.length()%2!=0)
		{
			cout<<":("<<endl;
			return 0;
		}
		lli x=t.length()/2;
		// string a=t.substr(0,x);
		// string b=t.substr(x);
		//cout<<a<<" "<<b<<endl;
		if(t.substr(0,x)==t.substr(x))
		{
			cout<<t.substr(x)<<endl;
			return 0;
		}
		else
		{
			cout<<":("<<endl;
			return 0;
		}
	}
	else
	{
		//cout<<ind<<endl;
		for(lli i=0;i<ind;i++)
		{
			if(t[i]!='a')
				s=s+t[i];
		}
		for(lli j=ind;j<t.length()-1;j++)
		{
			if(t[j]!='a')
				s=s+t[j];
			string b=t.substr(j+1);
			//cout<<s<<" "<<b<<endl;
			if(s==t.substr(j+1))
			{
				cout<<t.substr(0,j+1)<<endl;
				return 0;
			}

			if(s.length()>b.length())
			{
				break;
			}
			//s="";
			
		}
		//else
			{
				cout<<":("<<endl;
				return 0;
			}
		
	}


}