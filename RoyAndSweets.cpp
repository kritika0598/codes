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
	lli Sweet[N];
	lli Quantity[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Sweet[i]>>Quantity[i];
	}
	lli G;
	cin>>G;
	lli Member[G];
	for(lli i=0;i<G;i++)
	{
		cin>>Member[i];
	}
}