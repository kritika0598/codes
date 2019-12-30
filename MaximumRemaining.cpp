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

	set<lli> s;
	set<lli> :: iterator itr;
	lli x;
	lli max=1;
	lli smax=0;
	for(lli i=0;i<N;i++)
	{
		cin>>x;
		s.insert(x);
		if(i==0)
		{
			max=x;

		}
		else
		{
			if(x>max)
			{
				smax=max;
				max=x;
			}
			else if(x>smax && x!=max)
			{
				smax=x;
			}
		}
	}

	cout<<smax<<endl;


}