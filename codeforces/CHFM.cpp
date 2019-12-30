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
		map<lli,vector<lli>> m;
		lli N;
		cin>>N;
		lli sum=0;
		lli x;
		for(lli i=0;i<N;i++)
		{
			cin>>x;
			sum+=x;
			m[x].push_back(i);
		}

		if(sum%N!=0)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			sum=sum/N;
			if(m.find(sum)==m.end())
			{
				cout<<"Impossible"<<endl;
			}
			else
			{
				lli b=m[sum][0];
				cout<<b+1<<endl;
			}
		}

	}		
}