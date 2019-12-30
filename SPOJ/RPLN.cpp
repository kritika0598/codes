#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[1000005];
lli lookup[1000005][20];

void build(lli N)
{
	for(lli i=0;i<N;i++)
	{
		lookup[i][0]=Arr[i];
	}

	for(lli j=1;(1<<j)<=N;j++)
	{
		for(lli i=0;(i+(1<<j))<=N;i++)
		{
			lookup[i][j]=min(lookup[i][j-1],lookup[i+(1<<(j-1))][j-1]);
		}
	}
}

lli query(lli l, lli r)
{
	lli j=floor(log2(r-l+1));

	return min(lookup[l][j],lookup[r-(1<<j)+1][j]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	lli k=1;
	while(T--)
	{
		lli N,Q;
		cin>>N>>Q;
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}
		build(N);
		cout<<"Scenario #"<<k<<":"<<endl;
		while(Q--)
		{
			lli l,r;
			cin>>l>>r;
			cout<<query(l-1,r-1)<<endl;
		}
		k++;

	}
}