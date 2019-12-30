#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,r;
	cin>>N>>r;
	lli R;
	for(lli i=0;i<N;i++)
	{
		cin>>R;
		if(R<r)
			cout<<"Bad boi"<<endl;
		else
			cout<<"Good boi"<<endl;
	}
		
}