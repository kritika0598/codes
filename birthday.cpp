#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M,K,L;
	cin>>N>>M>>K>>L;
	if(M>N || K>N || L>N)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	else
	{
		if(K+L>N)
		{
			cout<<"-1"<<endl;
			return 0;
		}	
		else
		{
			if(M>=(K+L))
			{
				cout<<"1"<<endl;
			}
			else
			{
				lli x=((K+L)/M);
				while(x*M-K<L)
					x++;
				if((x*M)>N)
					cout<<"-1"<<endl;
				else
					cout<<x<<endl;
				return 0;
			}	

		}
	}
		
}