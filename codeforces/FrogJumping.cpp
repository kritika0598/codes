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
		lli a,b,k;
		cin>>a>>b>>k;
		if(k%2==0)
		{
			lli x=a*(k/2) - b*(k/2);
			cout<<x<<endl;
		}
		else
		{
			lli x=a*(k/2+1)- b*(k/2);
			cout<<x<<endl;
		}
	}
		
}