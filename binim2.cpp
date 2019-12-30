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
		string S;
		cin>>S;
		lli x;
		if(S=="Dee")
			x=0;
		else
			x=1;
		lli arr[55][55];
		string s;
		for(lli i=0;i<N;i++)
		{
			cin>>s;
			lli y=s.size();
			for(lli j=0;j<y;j++)
			{
				if(s[j]=='0')
					arr[i][j]=0;
				else
					arr[i][j]=1;
			}
		}
	}
		
}