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
		lli x;
		lli ans=0;
		lli b=0;
		for(lli i=0;i<N;i++)
		{
			cin>>x;
			if(x%3==0)
			{
				ans++;
			}
			else
			{
				x=x%3;
				b+=x;
			}
		}
		cout<<ans+(b/3)<<endl;
	}
}