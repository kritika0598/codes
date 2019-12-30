#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a,b,c,D;
	cin>>a>>b>>c>>D;
	lli sum=a+b+c;
	lli A=min(a,min(b,c));
	lli C=max(a,max(b,c));
	lli B=(sum-A-C);
	lli ans=0;
	if(C-B<D)
		ans+=D-(C-B);
	if(B-A<D)
		ans+=D-(B-A);

	cout<<ans<<endl;
}