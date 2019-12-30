#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	if(M%N!=0)
		cout<<-1<<endl;
	else
	{
		lli x=M/N;
		lli count=0;
		while(x%2==0 && x>1)
		{
			count++;
			x=x/2;
		}
		while(x%3==0 && x>2)
		{
			count++;
			x=x/3;
		}
	//	cout<<x<<endl;
		if(x==0 || x==1)
			cout<<count<<endl;
		else
			cout<<-1<<endl;
	}
}