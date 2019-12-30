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
	lli x=2;
	while(x!=N)
	{
		ans+=(x*(x+1));
		x=x+1;
	}

	cout<<ans<<endl;	
}