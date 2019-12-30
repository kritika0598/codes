#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	if(n%4==0 || n%4==3)
		cout<<0<<endl;
	else
		cout<<1<<endl;		
}