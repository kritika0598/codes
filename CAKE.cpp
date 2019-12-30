#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli level[100005];
lli bfs(lli S, lli D, vector<lli> graph[])
{
	level[S]=0;
	queue<lli> q;
	q.push(S);
	while(!q.empty())
	{
		lli x=q.front();
		//cout<<x<<" "<<level[x]<<endl;
		q.pop();
		if(x==D)
		{
			return level[x];
		}
		for(lli i=0;i<graph[x].size();i++)
		{
			if(level[graph[x][i]]>level[x]+1)
			{
				level[graph[x][i]]=min(level[x]+1,level[graph[x][i]]);
				q.push(graph[x][i]);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,E,S,D;
		cin>>N>>E>>S>>D;
		vector<lli> graph[N+1];
		for(lli i=0;i<E;i++)
		{
			lli x,y;
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		for(lli i=1;i<=N;i++)
		{
			level[i]=INT_MAX;
		}

		cout<<bfs(S,D,graph)<<endl;
	}
}