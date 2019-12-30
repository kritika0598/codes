#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	lli ans=0;
	while(n)
	{
		if(n==1)
			break;
		if(n%10==0)
		{
			n=n/10;
			ans++;
			continue;
		}
		n=n+1;
		ans++;


	}

	cout<<ans<<endl;
}