#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[30005];
struct d
{
	set<lli> s;
	int val;
} lookup[30005][20];

set<lli> :: iterator itr;
set<lli> :: iterator itr1;


void build(lli N)
{
	for(lli i=0;i<N;i++)
	{
		lookup[i][0].val=1;
		lookup[i][0].s.insert(Arr[i]);
	}

	for(lli j=1;(1<<j)<N;j++)
	{
		for(lli i=0 ;(i+(1<<j)-1)<N;i++)
		{
			//if(lookup[i][j-1].s.size()<lookup[i+(1<<(j-1))][j-1].s.size())
			// if(lookup[i][j-1].s.size()==((1<<(j-1))))
			// {
			// 	lookup[i][j].s=lookup[i][j-1].s;
			// }
			// else
			// {
			// 	for(itr= lookup[i][j-1].begin(); itr!=lookup[i][j-1].end();itr++)
			// 	{
			// 		itr1=lookup[i+(1<<(j-1))][j-1].s.find(*itr);
			// 		if(itr1==lookup[i+(1<<(j-1))][j-1].s.end())
			// 			lookup[i][j].s.insert(*itr);
			// 	}
			// }
				
			// 	for(itr= lookup[i+(1<<(j-1))][j-1].begin(); itr!=lookup[i+(1<<(j-1))][j-1].end();itr++)
			// 	{
			// 		itr1=lookup[i][j-1].s.find(*itr);
			// 		if(itr1==lookup[i][j-1].s.end())
			// 			lookup[i][j].s.insert(*itr);
			// 	}
			
			// lookup[i][j].val=lookup[i][j].s.size();

			set<lli> :: iterator it;

			it=set_union(lookup[i][j-1].s.begin(), lookup[i][j-1].s.end(),lookup[i+(1<<(j-1))][j-1].s.begin(),lookup[i+(1<<(j-1))][j-1].s.end(),lookup[i][j].s.begin());
			lookup[i][j].val=lookup[i][j].s.size();
		}
	}

}

lli query(lli L, lli R)
{
	lli j=floor(log2(R-L+1));
	lli ans=0;
	set<lli> st;
	set<lli> :: iterator itr;
	itr=set_union(lookup[L][j].s.begin(),lookup[L][j].s.end(),lookup[R-(1<<j)+1][j].s.begin(),lookup[R-(1<<j)+1][j].s.end(),st.begin());
	return st.size();

	// if(lookup[L][j].s.size()==((1<<(j))))
	// 		{
	// 			lli ans=ans+(1<<(j));
	// 			//lookup[i][j].s=lookup[i][j-1].s;
	// 		}
	// 		else
	// 		{
	// 			for(itr= lookup[L][j].begin(); itr!=lookup[L][j].end();itr++)
	// 			{
	// 				itr1=lookup[R-(1<<(j))+1][j].s.find(*itr);
	// 				if(itr1==lookup[R-(1<<(j))+1][j].s.end())
	// 				{
	// 					//lookup[L][j].s.insert(*itr);
	// 					ans++;
	// 				}	
	// 			}
	// 		}
				
	// 			for(itr= lookup[i+(1<<(j-1))][j-1].begin(); itr!=lookup[i+(1<<(j-1))][j-1].end();itr++)
	// 			{
	// 				itr1=lookup[i][j-1].s.find(*itr);
	// 				if(itr1==lookup[i][j-1].s.end())
	// 					lookup[i][j].s.insert(*itr);
	// 			}
			
	// 		lookup[i][j].val=lookup[i][j].s.size();
	// return min(lookup[L][j],lookup[R-(1<<j)+1][j]);
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
	lli Q;
	cin>>Q;
	while(Q--)
	{
		lli x,y;
		cin>>x>>y;
		lli ans=query(x,y);
		cout<<ans<<endl;
	}
}