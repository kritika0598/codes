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
		vector<lli> v;

		lli N;
		cin>>N;

		string s;
		cin>>s;
		char a;
		cin>>a;

		for(lli i=0;i<N;i++)
		{
			if(s[i]==a)
			{
				v.push_back(i);
			}
		}
		lli ans=0;
		if(v.size()!=0)
		{
			for(lli i=0;i<v.size();i++)
			{
				ans+=((v[i]+1) *(N-v[i]) );
			}

			for(lli i=0;i<v.size()-1;i++)
			{
				ans-=((v[i]+1)*(N-v[i+1]));
			}
		}
		

		cout<<ans<<endl;
	}		
}