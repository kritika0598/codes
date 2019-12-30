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
	string s1;
	string x;
	getline(cin,x);
	while(T--)
	{
		getline(cin,s1);
		//cout<<s<<endl;
		string s2="not";
		lli s=s1.length();
		bool flag=false;

		for(lli i=0;i<s-2;i++)
		{
			if(s1[i]=='n' && s1[i+1]=='o' && s1[i+2]=='t')
			{
				cout<<"Real Fancy"<<endl;
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			cout<<"regularly fancy"<<endl;
		}
		// if (s1.find(s2) != std::string::npos) 
		// {
  //   		cout <<"Real Fancy"<<endl;
		// }
		// else
		// {
		// 	cout<<"regularly fancy"<<endl;
		// }
	}
		
}