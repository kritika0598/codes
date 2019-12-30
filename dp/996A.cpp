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
	lli ans=0;
	while(N)
	{
		if(N/100!=0)
		{
			ans+=(N/100);
			N=N%100;
		}
		else if(N/20 !=0)
		{
			ans+=(N/20);
			N=N%20;
		}
		else if(N/10!=0)
		{
			ans+=(N/10);
			N=N%10;
		}
		else if(N/5!=0)
		{
			ans+=(N/5);
			N=N%5;
		}
		else
		{
			ans+=N;
			N=0;
		}
	}
	cout<<ans<<endl;	
}