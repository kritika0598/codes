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
	lli Arr[N+1];
	for(lli i=1;i<=N;i++)
	{
		cin>> Arr[i];
	}
	lli c=0;

	set<lli> s;

	for(lli i=1;i<=N;i++)
	{
		s.insert(Arr[i]);

		if(*s.begin()==i && s.size()==1)
		{
			c++;
			s.clear();
		}
		else if(*s.begin()==i)
		{
			s.erase(s.begin());
		}

	}

	cout<<c<<endl;
}