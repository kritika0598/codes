#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli N,Q;
lli Arr[200005];
vector<lli> graph[200005];
set<lli> level[200005];
set<lli> :: iterator itr;
lli maxi=0;
void solve(lli node, lli l)
{
	if(l>maxi)
		maxi=l;
	level[l].insert(Arr[node]);
	for(lli i=0;i<graph[node].size();i++)
	{
		solve(graph[node][i],l+1);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>N>>Q;

	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
	}
	for(lli i=1;i<N;i++)
	{
		lli x,y;
		cin>>x>>y;
		graph[x].push_back(y);
	}

	solve(1,0);
	while(Q--)
	{
		lli l,k;
		cin>>l>>k;
		l=l%(maxi+1);
		// cout<<l<<endl;
		// for(itr=level[l].begin();itr!=level[l].end();itr++)
		// {
		// 	cout<<*itr<<" ";
		// }
		// cout<<endl;
		itr=level[l].lower_bound(k);
		if(itr==level[l].end())
			cout<<-1<<endl;
		else
			cout<<(*itr)<<endl;
	}
}