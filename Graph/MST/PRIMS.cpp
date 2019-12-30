#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli N,M;
bool visited[1000005];

vector<pair<lli,lli>> graph[1000005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	memset(visited,false,sizeof(visited));
	lli x,y,z;
	for(lli i=0;i<M;i++)
	{
		cin>>x>>y>>z;
		graph[x].push_back(make_pair(z,y));
		graph[y].push_back(make_pair(z,x));
	}

	visited[1]=true;
	priority_queue<pair<lli,lli>, vector<pair<lli,lli>>, greater<pair<lli,lli>>> pq;
	//priority_queue<pair<lli,lli>, greater<pair<lli,lli>>> pq;
	for(lli i=0;i<graph[1].size();i++)
	{
		pq.push(graph[1][i]);
	}
	lli ans=0;
	pair<lli,lli> c;
	while(!pq.empty())
	{
		c=pq.top();
		pq.pop();
		lli m=c.second;
		if(visited[m])
			continue;
		visited[m]=true;
		ans+=c.first;
		//cout<<m<<" "<<ans<<endl;
		

		for(lli i=0;i<graph[m].size();i++)
		{
			if(visited[graph[m][i].second]==false)
			{
				pq.push(graph[m][i]);
			}
		}
	}

	cout<<ans<<endl;
}