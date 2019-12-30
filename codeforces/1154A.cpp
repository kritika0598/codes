#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli x,y,z,m;
	cin>>x>>y>>z>>m;

	lli a=max(x,max(y,max(z,m)));

	if(a-x!=0)
		cout<<a-x<<" ";
	if(a-y!=0)
		cout<<a-y<<" ";
	if(a-z!=0)
		cout<<a-z<<" ";
	if(a-m!=0)
		cout<<a-m<<" ";
}