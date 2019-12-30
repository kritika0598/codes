#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli MOD=1000000007;

lli power(lli a, lli b, lli M)
{
	lli res=1;
	b=b%M;
	while(b>0)
	{
		if(b&1)
			res=(res*a)%MOD;
		a=(a*a)%MOD;
		b=b>>1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;

	lli a=power(3,3*N,MOD)%MOD;
	lli b=power(7,N,MOD)%MOD;

	lli ans=((a%MOD)-(b%MOD)+MOD)%MOD;
	cout<<ans<<endl;
}