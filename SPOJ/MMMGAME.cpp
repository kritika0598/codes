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
		bool f=true;
		lli ans=0;
		for(lli i=0;i<N;i++)
		{
			lli x;
			cin>>x;
			if(x!=1)
				f=false;
			ans=ans^x;
		}

		if(f)
		{
			if(N%2==0)
			{
				cout<<"John"<<endl;
			}
			else
			{
				cout<<"Brother"<<endl;
			}
		}
		else
		{
			if(ans==0)
			{
				cout<<"Brother"<<endl;
			}
			else
			{
				cout<<"John"<<endl;
			}
		}
	}
}