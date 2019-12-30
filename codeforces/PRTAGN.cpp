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
		lli Q;
		cin>>Q;
		map<lli,lli> m;
		lli o=0;
		lli e=0;

		while(Q--)
		{
			lli x;
			cin>>x;
			map<lli,lli> :: iterator itr;
			itr=m.begin();
			while(itr!=m.end())
			{
				if(x!=itr->first && m.find(x^(itr->first))==m.end())
				{
					lli a=__builtin_popcount(x^(itr->first));
					if(a%2==0)
					{
						e++;
					}
					else
					{
						o++;
					}
					m[x^(itr->first)]++;
				}
				itr++;
			}
			if(m.find(x)==m.end())
			{
				if(__builtin_popcount(x)%2==0)
				{
					e++;
				}
				else
				{
					o++;
				}
				m[x]++;
			}

			cout<<e<<" "<<o<<endl;

		}

	}
}