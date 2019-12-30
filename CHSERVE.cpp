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
	lli P1,P2,K;
	while(T--)
	{
		cin>>P1>>P2>>K;
		lli s=P1+P2;
		s=s/K;
		if(s%2==1)
			cout<<"COOK"<<endl;
		else
			cout<<"CHEF"<<endl;
	}
		
}