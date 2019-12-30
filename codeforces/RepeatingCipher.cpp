#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	string s;
	cin>>s;
	string a;
	lli x=1;
	for(lli i=0;i<N;i=i+x)
	{
		x=x+1;
		a=a+s[i];
	}
	cout<<a<<endl;
}