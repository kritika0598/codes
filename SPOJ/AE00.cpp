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
	lli x=0;
	lli y;
	x=x+(N);
	for(lli i=2;i<=N;i++)
	{
		y=N/i;
		if(y-i+1>=0)
			x=x+(y-i+1);
	}
	cout<<x<<endl;
}