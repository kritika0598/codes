#include<iostream>
#include<bits/stdc++.h>
#define MOD 998244353
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
		double x;
		cin>>x;
		bool flag=true;
		double y=ceil(180/x);
		if(y<3)
			y=3;
		while(flag && y<=998244353)
		{
			double a=180/y;
			if(fmod(x,a)==0 && ((y-2)*180/y)>=x)
			{
				flag=false;
				cout<<y<<endl;
			}
			else
			{
				y++;
			}
		}
		if(flag)
			cout<<-1<<endl;

	}
		
}