#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	map<lli,lli> m;
	lli p=0;
	lli ans=0;
	if(N%2==0)
	{
		p=N/2;
	}
	else
	{
		p=(N/2)+1;
	}
	for(lli i=0;i<N;i++)
	{
		lli x;
		cin>>x;
		m[x]++;
		if(m[x]==2 && p>0)
		{
			ans+=2;
			p--;
			m[x]=0;
		}
	}

	if(p>0)
	{
		ans+=p;
	}

	cout<<ans<<endl;

}