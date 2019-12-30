#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	lli n=s.length();
	lli x=-1;
//	cout<<s<<endl;
	for(lli i=0;i<n;i++)
	{
		if(s[i]=='[')
		{
			//cout<<"hello"<<endl;
			x=i;
			break;
		}
	}
	if(x==-1)
	{
		cout<<-1<<endl;
		return 0;
	}
	lli y=-1;
	for(lli i=x+1;i<n;i++ )
	{
		if(s[i]==':')
		{
			y=i;
			break;
		}
		
	}
	if(y==-1)
		{
			cout<<-1<<endl;
			return 0;
		}
	lli z=-1;
	lli count=0;
	for(lli i=n-1;i>=y;i--)
	{
		if(s[i]==']')
		{	
			z=i;
			break;
		}
	}

	if(z==-1)
	{
	//	else
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	lli w=-1;
	for(lli i=z-1;i>y;i--)
	{
		if(s[i]==':')
		{
			w=i;
			break;
		}
	}
	if(w==-1)
	{
		//else
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	for(lli i=w-1;i>y;i--)
	{
		if(s[i]=='|')
		{
			count++;
			//break;
		}
	}
	cout<<count+4<<endl;

}