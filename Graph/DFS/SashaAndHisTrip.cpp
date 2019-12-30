#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,v;
	cin>>N>>v;

	lli x=N-1;
	lli ans=0;

	if(v>=N-1)
	{
		cout<<N-1<<endl;
	}
	else
	{
		ans=ans+(v);
		x=x-v;
		lli i=2;
		while(x!=0)
		{
			ans=ans+(i);
			x--;
			i++;

		}

		cout<<ans<<endl;
	}

}