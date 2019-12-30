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
	while(N--)

	{
		string s;
		cin>>s;
	//	cout<<s<<endl;
		stack<char> s1;
		stack<char> s2;
		string ans="";

		for(lli i=0;i<s.length();i++)
		{
			if(s[i]=='(')
			{
				s1.push(s[i]);
			//	cout<<"ehllo"<<endl;
			}	
			else
			{
				if(s[i]>=97 && s[i]<=122)
				{
				//	cout<<"ehllo"<<endl;
					cout<<s[i];
				}
				else if(s[i]==')')
				{
				//	cout<<"ehllo"<<endl;
					s1.pop();
					cout<<s2.top();
					s2.pop();
				}
				else
				{
					s2.push(s[i]);
				}

			}

		//	cout<<s1.top()<<" "<<s2.top()<<endl;
			

		}
		cout<<endl;
	}
}