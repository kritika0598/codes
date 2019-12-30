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

	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	map<lli,lli> m;
	lli count=0;
	for(lli i=1;i<N;i++)
	{
		for(lli j=0;j<i;j++)
		{
			if(Arr[j]>Arr[i])
			{
				m[j]++;
				m[i]++;
				count++;
			}
		}
	}
	lli c=0;
	lli mini=INT_MAX;
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		if(m[i]==0)
			c++;
		else 
		{
			if(m[i]<mini)
				mini=m[i];
		}
	}

	if(c>=K)
		cout<<count<<endl;
	else
	{

	}
}