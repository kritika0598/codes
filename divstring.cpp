#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	string s;
	cin>>s;
	bool flag=false;
	for(lli i=0;i<n-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			flag=true;
			cout<<"YES"<<endl;
			cout<<s[i]<<s[i+1]<<endl;
			break;
		}
	}
	if(!flag)
		cout<<"NO"<<endl;
		
}