#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a,b;
	cin>>a>>b;
	lli p=a,q=b,r=a+1;
	lli x=(a*b);
	lli y =__gcd(a,b);
	if(x/y==a || x/y==b)
	{
		cout<<0<<endl;
		return 0;
	}
	lli maxi=__gcd(a,b);
	lli ans=x/y;
	lli a1=x/y;
	lli v=0;
	lli g=0;
	lli e=ans;
	while(1)
	{
		if((p-a)>abs(a-b) || (q-b)>abs(a-b))
		{
			break;
		}
		lli t=__gcd(p,q);
		if(t>maxi)
		{
			maxi=t;
			if(((p*q)/maxi)<ans)
			{
				ans=(p*q)/maxi;
				v=p-a;
			}
		}
	//	cout<<t<<" "<<p<<" "<<q<<" "<<maxi<<" "<<ans<<endl;
		p++;
		q++;
		g++;
		
		//g++;
	}
	cout<<v<<endl;
	//cout<<x/y<<" "<<y<<endl;		
}