#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	lli N;
	cin>>N;
	if(N%2==1)	
	{
		cout<<0<<endl;
	}
	else
	{
		lli ans=1;
		for(lli i=N/2;i>0;i--)
		{
			ans*=2;
		}
		cout<<ans<<endl;
	}
}