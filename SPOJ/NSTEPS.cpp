#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli x,y;
		cin>>x>>y;
		if(x==y)
		{
			if(x%2==0)
			{
				cout<<2*x<<endl;
			}
			else
			{
				cout<<2*x-1<<endl;
			}
		}
		else if(x==y+2)
		{
			if(x%2!=0)
			{
				cout<<x+y-1<<endl;
			}
			else
			{
				cout<<x+y<<endl;
			}
		}
		else
		{
			cout<<"No Number"<<endl;
		}
	}
}