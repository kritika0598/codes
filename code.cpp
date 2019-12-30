#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,A,B;
	cin>>N>>A>>B;

	lli x= N/A;
	x+=N/B;

	lli m=__gcd(A,B);

	lli n=A*B;

	lli lcm=n/m;

	x-=(N/lcm);

	cout<<x<<endl;	
}