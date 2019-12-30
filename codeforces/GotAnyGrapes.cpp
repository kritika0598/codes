#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli x,y,z;
	cin>>x>>y>>z;
	lli a,b,c;
	cin>>a>>b>>c;
	if(x>a)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		a=a-x;
	}
	bool flag=true;
	if(a>=y)
	{
		a=a-y;
	}
	else if(b>=y)
	{
		b=b-y;
	}
	else
	{
		if(a+b>=y)
		{
			y=y-a;
			a=0;
			b=b-y;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	if(a+b+c>=z)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

	return 0;	
}