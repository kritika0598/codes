#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;

	lli cnt=0;

	for(lli i=0;i<s.length();i++)
	{
		if(s[i]=='a')
			cnt++;
	}
	cnt=2*cnt-1;
	lli sz=s.length();
	cout<<min(sz, cnt)<<endl;
		
}