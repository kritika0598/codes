#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[100005];
lli lookup[100005][20];

void build(lli N)
{
	for(lli i=0;i<N;i++)
	{
		lookup[i][0]=Arr[i];
	}

	for(lli j=1;(1<<j)<N;j++)
	{
		for(lli i=0 ;(i+(1<<j)-1)<N;i++)
		{
			lookup[i][j]=min(lookup[i][j-1],lookup[i+(1<<(j-1))][j-1]);
		}
	}

}

lli query(lli L, lli R)
{
	lli j=floor(log2(R-L+1));
	return min(lookup[L][j],lookup[R-(1<<j)+1][j]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;

	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	build(N);
	lli M;
	cin>>M;
	while(M--)
	{
		lli L,R;
		cin>>L>>R;
		cout<<query(L,R)<<endl;
	}
}