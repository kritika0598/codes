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
		lli N;
		cin>>N;
		//lli x;
		//lli ans=(N/25);
		//ans=ans+2*N/10;
	//	cout<<ans<<endl;
	//	cout<<N/4<<endl;
		lli a=0;
		for(lli i=5;i<=N;i=i*5)
		{
			a=a+(N/i);
		}
		cout<<a<<endl;
	}
}