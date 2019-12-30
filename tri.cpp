#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a,b,c;
	cin>>a>>b>>c;
	lli x,y,z;
	x=a+b;
	y=b+c;
	z=c+a;
	lli sum=0;
	if(a>=y)
	{
		sum=sum+(a-y) +1;
	}
	if(b>=z)
	{
		sum=sum+(b-z)+1;
	} 
	if(c>=x)
	{
		sum=sum+(c-x)+1;
	}
	cout<<sum<<endl;
		
}