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
	lli count=0;
	// for(lli i=0;i<N;i++)
	// {
	// 	if(s[i]=='R')
	// 		s[i]='1';
	// 	else if(s[i]=='G')
	// 		s[i]='2';
	// 	else
	// 		s[i]='3';
	// }
	if(N==1)
	{
		cout<<0<<endl;
		cout<<s<<endl;
		return 0;
	}
	for(lli i=0;i<N-2;i++)
	{
		if(s[i]==s[i+1])
		{
			count++;
			if(s[i]!=s[i+2])
			{
				if(s[i]=='R' && s[i+2]=='B')
					s[i+1]='G';
				else if(s[i]=='R' && s[i+2]=='G')
					s[i+1]='B';
				else if(s[i]=='B' && s[i+2]=='R')
					s[i+1]='G';
				else if(s[i]=='B' && s[i+2]=='G')
					s[i+1]='R';
				else if(s[i]=='G' && s[i+2]=='R')
					s[i+1]='B';
				else if(s[i]=='G' && s[i+2]=='B')
					s[i+1]='R';
			}
			else
			{
				if(s[i]=='R')
					s[i+1]='B';
				else
					s[i+1]='R';
			}
		}
	}
	if(s[N-2]==s[N-1])
	{
		count++;
		if(s[N-2]=='R')
			s[N-1]='B';
		else
			s[N-1]='R';
	}

	cout<<count<<endl;
	cout<<s<<endl;
}