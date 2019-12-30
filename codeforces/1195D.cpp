#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli MOD=998244353;

lli power(lli a, lli b, lli MOD)
{
	a=a%MOD;
	lli res=1;
	while(b>0)
	{
		if(b&1)
		{
			res=(res*a)%MOD;
		}
		b=b>>1;
		a=(a*a)%MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli ans=0;
	for(lli i=0;i<N;i++)
	{
		lli x;
		cin>>x;
		lli j=0;
		while(x>0)
		{
			lli p=x%10;
			lli z=((((N%MOD)*(p)*(power(10,j,MOD)%MOD))))%MOD;
			z=((z%MOD)+((((N%MOD)*(p)*(power(10,j+1,MOD)%MOD))))%MOD)%MOD;
			ans=((ans%MOD)+(z%MOD))%MOD;
			j=j+2;
			x=x/10;
		}
	}

	cout<<ans<<endl;	
}