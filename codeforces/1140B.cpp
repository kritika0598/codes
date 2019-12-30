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
		lli N;
		cin>>N;
		string s;
		cin>>s;

		stack<char> st;
		st.push(s[0]);
		for(lli i=1;i<N;i++)
		{
			if(s[i]=='>' && st.top()!='>')
				st.push('>');
			else if(s[i]=='<')
			{
				st.pop();
				st.push('<');
			}
		}

		lli x=st.size();

		cout<<st.size()-1<<endl;
	}
}