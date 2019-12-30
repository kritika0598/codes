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
		lli a,b;
		cin>>a>>b;
		if(a==-1)
			return 0;
		if(a==1 || b==1)
		{
			cout<<a<<"+"<<b<<"="<<a+b<<endl;
		}
		else
		{
			cout<<a<<"+"<<b<<"!="<<a+b<<endl;
		}
	}
}