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
		lli n,a,b;
		cin>>n>>a>>b;
		if(n%2==0)
		{
			if(2*a>b)
			{
				cout<<b*(n/2)<<endl;
			}
			else
			{
				cout<<2*a*(n/2)<<endl;
			}
		}
		else
		{
			if(2*a>b)
			{
				cout<<a+(b*(n/2))<<endl;
			}
			else
			{
				cout<<a+(2*a*(n/2))<<endl;
			}
		}
	}
}