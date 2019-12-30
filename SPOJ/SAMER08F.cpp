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
		lli N;
		cin>>N;
		if(N==0)
		{
			return 0;
		}

		lli count=N*N;
		for(lli i=2;i<=N;i++)
		{
			count=count+(N-(i-1))*(N-(i-1));
		}
		cout<<count<<endl;
	}
}