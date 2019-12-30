#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	lli x;
	while(t--)
	{
		cin>>x;
		if(x%2==0)
		{
			cout<<(x/2)<<endl;
		}
		else
		{
			x=x-3;
			cout<<1+(x/2)<<endl;
		}
	}
		
}