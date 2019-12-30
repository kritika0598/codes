#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,S;
	cin>>N>>S;
	if(S<=N)
	{
		cout<<"1"<<endl;
		return 0;
	}
	lli count=S/N;
	if(S%N!=0)
		count++;

	cout<<count<<endl;
	return 0;
}