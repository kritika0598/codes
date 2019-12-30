#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli visited[100005];

void dfs(vector<lli> graph[], lli src)
{
	stack<lli> s;
	s.push(src);
	while(!s.empty())
	{
		lli z=s.top();
		s.pop();
		if(visited[z])
			continue;
		visited[z]=true;
		for(lli i=0;i<graph[z].size();i++)
		{
			s.push(graph[z][i]);
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
		lli N;
		cin>>N;
		lli q;
		cin>>q;
		vector<lli> graph[N];
		for(lli i=0;i<q;i++)
		{
			lli x,y;
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		memset(visited,false,sizeof(visited));
		lli ans=0;
		for(lli i=0;i<N;i++)
		{
			if(visited[i]==false)
			{
				dfs(graph,i);
				ans++;
			}
		}

		cout<<ans<<endl;
	}
}