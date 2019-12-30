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
	lli x=N*N;
	map<lli,lli> m;
	set<lli> s;
	for(lli i=0;i<N;i++)
	{
		lli a;
		cin>>a;
		m[a]++;
		s.insert(a);
	}

	
}