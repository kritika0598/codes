#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli w1,h1,w2,h2;
	cin>>w1>>h1>>w2>>h2;
	lli ans=w1+2+w2+2+w1-w2+h1+h2+h1+h2;
	cout<<ans<<endl;	
}