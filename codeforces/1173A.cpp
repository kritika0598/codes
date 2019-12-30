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
	lli dif=abs(x-y);
	if(x==y && z==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(z>=dif)
	{
		cout<<"?"<<endl;
	}
	else
	{
		if(x>y)
		{
			cout<<"+"<<endl;
		}
		else if(y>x)
		{
			cout<<"-"<<endl;
		}
		else
		{
			cout<<0<<endl;
		}

	}
}