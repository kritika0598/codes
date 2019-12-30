#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli n,k;
		cin>>n>>k;

		lli x=k+1;
		if(n==1 || n==2 || n==k)
		{
			cout<<"Alice"<<endl;
		}
		else if(n<k)
		{
			cout<<"Bob"<<endl;
		}
		else if(n%(k+1)==0)
		{
			cout<<"Bob"<<endl;
		}
		else
		{
			cout<<"Alice"<<endl;
		}
	}
}