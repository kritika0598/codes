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
	string s;
	cin>>s;
	stack<char> c;
	lli t=1;
	c.push(s[0]);
	for(lli i=1;i<N;i++)
	{
		if(c.top()<=s[i])
		{
			c.push(s[i]);
			t=i+1;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<t<<" "<<i+1<<endl;
			return 0;
		}
	}

	cout<<"NO"<<endl;



}
