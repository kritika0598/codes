#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli N;
lli a=0;

lli DP


void foo(lli mask1,lli mask2, vector<lli> v[])
{
	if(mask1==((1<<N)-1) && mask2==((1<<N)-1) )
		a++;
	for(lli i=1;i<N;i++)
	{
		if(!(mask1&(1<<i)))
		{
			for(lli j=0;j<v[i].size();j++)
			{
				if(!(mask2&(1<<v[i][j])))
				{
					foo(mask1|(1<<i), mask2|(1<<j),v);

				}
			}
		}

	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		vector<lli> v[N];
		lli x;
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				cin>>x;
				if(x==1)
				{
					v[j].push_back(i);
				}
			}
		}
		lli ans=0;
		for(lli i=0;i<v[0].size();i++)
		{
			lli mask1=1;
			lli mask2=(1<<v[0][i]);
			//cout<<mask1<<" "<<mask2<<endl;
			foo(mask1,mask2,v);
		}
		cout<<a<<endl;
		a=0;
	}
}