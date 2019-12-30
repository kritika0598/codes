#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,k;
	cin>>n>>m>>k;
	if(m<n)
	{
		cout<<"No"<<endl;
		return 0;
	}
	if(k<n)
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;

}