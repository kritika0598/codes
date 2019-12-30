#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli x,y,z;
	cin>>x>>y>>z;

	lli a=x/z;
	lli b=y/z;

	lli c=x-(a*z);
	lli d=y-(b*z);
	lli ans=a+b;
	ans+=(c+d)/z;
	lli s=(c+d)/z;

	lli q=c+d-(z*s);

	lli t=min(c,d);
	lli f=t-q;
	if(f<0)
		f=0;
	cout<<ans<<" "<<f<<endl;


}