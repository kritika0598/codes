#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli q;
	cin>>q;
	while(q--)
	{
		lli l,r,d;
		cin>>l>>r>>d;
		if(d<l)
		{
			cout<<d<<endl;
		}
		else
		{
			lli x=r/d;
			x=d*(x+1);

			cout<<x<<endl;
		}
	}
}