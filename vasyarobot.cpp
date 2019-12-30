#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	string s;
	cin>>s;
	lli x,y;
	lli a=0,b=0;
	for(lli i=0;i<n;i++)
	{
		if(s[i]=='R')
			a++;
		else if(s[i]=='L')
			a--;
		else if(s[i]=='U')
			b++;
		else if(s[i]=='D')
			b--;
	}
	cin>>x>>y;
	if(n<(x+y))
		cout<<"-1"<<endl;
	else if(a==x && b==y)
		cout<<"0"<<endl;
	else
	{
		lli c,d;
		lli mini=n;
		lli maxi=0;
		//for(lli i=0;i<n;i++)
		{
			if(x<a)
			{
				for(lli i=0;i<n;i++)
				{
					if(s[i]=='R')
					{
						if(i<mini)
							mini=i;
						if(i>maxi)
							maxi=i;
					}
					a=a-2;
					if(a==x)
						break;
				}
				
				cout<<mini<<" "<<maxi<<endl;
			}
			else if(x>a)
			{
				for(lli i=0;i<n;i++)
				{
				if(s[i]=='L')
				{
					if(i<mini)
						mini=i;
					if(i>maxi)
						maxi=i;
				}
				a=a+2;
			}
			}
			if(y<b)
			{
				for(lli i=0;i<n;i++)
				{
					if(s[i]=='U')
					{
						if(i<mini)
							mini=i;
						if(i>maxi)
							maxi=i;
					}
					b=b-2;
				}
				

			}
			else if(y>b)
			{
				for(lli i=0;i<n;i++)
				{
					if(s[i]=='D')
					{
						if(i<mini)
							mini=i;
						if(i>maxi)
							maxi=i;
					}
					b=b+2;
				}
			}
		}
		if(x!=a || y!=b)
		{
			for(lli i=0;i<n;i++)
			{
				if(x<a && y<b)
				{
					if(s[i]=='U')
					{
						if(i<mini)
							mini=i;
						if(i>maxi)
							maxi=i;
					}
					a=a-1;
					b=b-1;
				}
				else if(x<a && y>b)
				{
					if(s[i]=='D')
					{
						if(i<mini)
							mini=i;
						if(i>maxi)
							maxi=i;
					}
					a=a-1;
					b=b+1;
				}
				else if(x<a && y==b)
				{
					cout<<"-1"<<endl;
					return 0;
				}
				if(x>a && y<b)
				{
					if(s[i]=='U')
					{
						if(i<mini)
							mini=i;
						if(i>maxi)
							maxi=i;
					}
					a=a+1;
					b=b-1;
				}
				else if(x>a && y>b)
				{
					if(s[i]=='D')
					{
						if(i<mini)
							mini=i;
						if(i>maxi)
							maxi=i;
					}
					a=a+1;
					b=b+1;
				}
				else if(x>a && y==b)
				{
					cout<<"-1"<<endl;
					return 0;
				}
			}
			

		}

		cout<<maxi-mini+1<<endl;

	}
		
}