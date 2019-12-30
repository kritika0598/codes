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

	lli u,vu;

	vector<lli> v[N+1];
	lli Brr[N+1];
	map<lli,lli> x;
	Brr[1]=0;
	for(lli i=0;i<N-1;i++)
	{
		cin>>u>>vu;
		v[u].push_back(vu);
		Brr[vu]=u;
	}
	lli Arr[N+1];
	vector<lli> c;
	vector<lli> :: iterator it;
	for(lli i=1;i<=N;i++)
	{
		if(v[i].size()!=0)
			Arr[i]=0;
		else
		{
			Arr[i]=1;
			x[i]=1;
		}	
	}

	for(lli i=N;i>=1;i--)
	{
		x[Brr[i]]+=x[i];
	}

	for(lli i=1;i<=N;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;

}