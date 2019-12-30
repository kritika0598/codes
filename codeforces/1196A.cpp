#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli q;
	cin>>q;
	while(q--)
	{
		lli a,b,c;
		cin>>a>>b>>c;

		lli s=a+b+c;
		s=s/2;
		cout<<s<<endl;
	}
}