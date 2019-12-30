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
	if(N%4==1)
	{
		cout<<0<<" A"<<endl;
	}
	else if(N%4==3)
	{
		cout<<2<<" A"<<endl;
	}
	else if(N%4==2)
	{
		cout<<1<<" B"<<endl;
	}
	else
	{
		cout<<1<<" A"<<endl;
	}
}