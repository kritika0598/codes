#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	map<lli,lli>m;
	m[2010]=1;
	m[2015]=1;
	m[2016]=1;
	m[2017]=1;
	m[2019]=1;
	while(T--)
	{
		lli N;
		cin>>N;
		if(m[N])
			cout<<"HOSTED"<<endl;
		else
			cout<<"NOT HOSTED"<<endl;
	}
		
}