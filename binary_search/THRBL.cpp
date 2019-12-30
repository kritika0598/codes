#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[50005];
lli lookup[50005][20];

void build(lli N)
{
	for(lli i=0;i<N;i++)
	{
		lookup[i][0]=Arr[i];
	}

	for(lli j=1;(1<<j)<N;j++)
	{
		for(lli i=0;(i+(1<<j)-1)<N;i++)
		{
			lookup[i][j]=max(lookup[i][j-1],lookup[i+(1<<(j-1))][j-1]);
		}
	}
}

lli query(lli l, lli r)
{
	lli j=floor(log2(r-l+1));

	return max(lookup[l][j],lookup[r-(1<<j)+1][j]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	lli count=0;
	build(N);
	while(M--)
	{
		lli l,r;
		cin>>l>>r;
		lli x;
		//cout<<query(l-1,r-1)<<endl;
		x=query(l-1,r-2);
		if(x<=Arr[l-1])
			count++;
	}

	cout<<count<<endl;
}