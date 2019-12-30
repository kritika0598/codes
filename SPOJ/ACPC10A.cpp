#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli a,b,c;
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0)
			return 0;

		if(b-a==c-b)
		{
			cout<<"AP"<<" "<<c+(c-b)<<endl;
		}
		else
		{
			cout<<"GP"<<" "<<c*(c/b)<<endl;
		}
	}
}