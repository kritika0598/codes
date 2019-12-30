#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
vector<lli> graph[100005];
vector<lli>graphT[100005];
bool visited[100005];
stack<lli> s;
lli cycle=0;
lli c[100005];
lli outdegree[100005];
lli ft[100005];
lli t=0;
void dfs(lli src)
{
	visited[src]=true;
	for(lli i=0;i<graph[src].size();i++)
	{
		if(!visited[graph[src][i]])
		{
			dfs(graph[src][i]);
		}
	}
	ft[src]++;
	s.push(src);

}

void dfs1(lli src, lli cmp)
{
	visited[src]=true;
	c[src]=cycle;
	for(lli i=0;i<graphT[src].size();i++)
	{
		if(!visited[graphT[src][i]])
		{
			dfs1(graphT[src][i],cmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	for(lli i=0;i<M;i++)
	{
		lli x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graphT[y].push_back(x);
	}
	memset(ft,-1,sizeof(ft));
	memset(c,0,sizeof(c));
	memset(visited,false,sizeof(visited));
	for(lli i=1;i<=N;i++)
	{
		if(!visited[i])
			dfs(i);
	}
	memset(visited,false,sizeof(visited));
	while(!s.empty())
	{
		lli z=s.top();
		s.pop();
		if(visited[z]==false)
		{
			cycle++;
			dfs1(z,ft[z]);
		}
	}

	for(lli i=1;i<=N;i++)
	{
		//cout<<c[i]<<endl;
		for(lli j=0;j<graph[i].size();j++)
		{
			if(c[i]!=c[graph[i][j]])
			{
				outdegree[c[i]]++;
			}
		}
	}
	lli cnt=0;
	for(lli j=1;j<=cycle;j++)
	{
		if(outdegree[j]==0)
			cnt++;
	}

	if(cnt>1)
	{
		cout<<0<<endl;
	}
	else
	{
		cnt=0;
		for(lli i=1;i<=N;i++)
		{
			if(outdegree[c[i]]==0)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
		for(lli i=1;i<=N;i++)
		{
			if(outdegree[c[i]]==0)
			{
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
}