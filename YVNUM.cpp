#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


string leftrotate(string s, int d) 
{ 
    reverse(s.begin(), s.begin()+d); 
    reverse(s.begin()+d, s.end()); 
    reverse(s.begin(), s.end());
    return s; 
} 


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		string st=s;
		for(lli i=1;i<s.length();i++)
		{
			//string x=leftrotate(s,i);,
			st=st+s.substr(i,s.length())+s.substr(0,i);
			//st=st+x;
		}
		std::string::size_type sz = 0;
		long long ll = std::stoll (st,&sz,0);
		ll=ll%1000000007;

		cout<<ll<<endl;

		//cout<<st<<endl;
	}
}