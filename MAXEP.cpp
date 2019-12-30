#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,c,s;
	lli coins=1000;
	cin>>N>>c;
	bool flag=true;
	lli l=1;
	lli r=N;
	lli y=(l+r)/2;
	lli x;
	while(flag && coins>=0)
	{
		//y=y/2;
		cout<<1<<" "<<y<<endl;
		coins--;
		x=y-1;
		//cout<<coins<<endl;
		cin>>s;
		if(s==1)
		{
			if(y==1)
			{
				x=0;
				flag=false;
			}
			r=y-1;
			cout<<2<<endl;
			coins=coins-c;
			//cout<<coins<<endl;
			y=(l+r)/2;
		}
		if(s==0)
		{
			l=y;
			y=(l+r)/2;
			if(r-l<=2)
			{
				flag=false;
				x=y;
			}	

		}
		else
		{
			continue;
		}
	}

	cout<<3<<" "<<x+1<<endl;
	

		
}