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
	lli x,y=0;
	while(N--)
	{
		cin>>x;
		y=y^x;
	}

	cout<<y<<endl;
}