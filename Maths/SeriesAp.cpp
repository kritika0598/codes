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
		lli a,b;
		cin>>a>>b;
		lli N;
		cin>>N;

		lli diff=b-a;
		cout<<a+(N-1)*(diff)<<endl;
	}
	return 0;
}