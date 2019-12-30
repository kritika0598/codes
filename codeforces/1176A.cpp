#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli Q;
	cin>>Q;

	while(Q--)
	{
		lli N;
		cin>>N;
		lli ans=0;
		bool flag=true;
		while(N!=1)
		{
			if(N%2==0)
			{
				N=N/2;
				ans++;
			}
			else if(N%3==0)
			{
				N=2*N/3;
				ans++;
			}
			else if(N%5==0)
			{
				N=4*N/5;
				ans++;
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
}