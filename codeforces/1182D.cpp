#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli dis[100005];
vector<lli> v1[100005];
vector<lli> ::iterator itr;

bool visited[100005];

void dfs(vector<lli> graph[],lli src)
{
	dis[src]=0;
//	visited[src]=true;
	stack<pair<lli,lli>> s;
	s.push({src,0});
	while(!s.empty())
	{
		pair<lli,lli> p=s.top();
		s.pop();
		lli x=p.first;
		lli l=p.second;
		if(visited[x])
			continue;
		visited[x]=true;
		dis[x]=l;
		v1[l].push_back(x);
		for(lli i=0;i<graph[x].size();i++)
		{
			if(visited[graph[x][i]]==false)
			{
				s.push({graph[x][i],l+1});
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	vector<lli> graph[N+1];
	lli u,v;
	for(lli i=0;i<N-1;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(lli i=1;i<=N;i++)
	{
		memset(visited,0,sizeof(visited));

		memset(dis,0,sizeof(dis));
		dfs(graph,i);
		bool flag=true;
		for(lli j=1;j<=N;j++)
		{
			if(v1[j].size()==0)
				break;
			for(lli k=0;k<v1[j].size()-1;k++)
			{
				if(graph[v1[j][k]].size()!=graph[v1[j][k+1]].size())
				{
					flag=false;
					break;
				}
			}
			if(flag==false)
			{
				break;
			}

		}

		if(flag)
		{
			cout<<i<<endl;
			return 0;
		}

	}
	//if(!flag)
	{
		cout<<-1<<endl;
	}


}