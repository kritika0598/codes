#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct cmpp
{
	bool operator()(pair<lli,lli> a,pair<lli,lli> b)
	{
		return a.second>b.second;
	}
};

int main() {
	lli N,M,Q;
	cin>>N>>M>>Q;
	vector<pair<lli,lli>> graph[N];
	lli x,y,d;
	for(lli i=0;i<M;i++)
	{
		cin>>x>>y>>d;
		graph[x].push_back({y,d});
		graph[y].push_back({x,d});
	}
	while(Q--)
	{
		lli src;
		cin>>src;
		lli dis[N];
		bool visited[N];
		for(lli i=0;i<N;i++)
		{
			dis[i]=10000000;
			visited[i]=false;
		}
		dis[src]=0;
		lli count=-1;
		lli maxi=-1;
		priority_queue<pair<lli,lli> ,vector<pair<lli,lli>> , cmpp> s;
		s.push({src,0});
		while(!s.empty())
		{
			pair<lli,lli> p=s.top();
			s.pop();
			lli a=p.first;
			lli b=p.second;
			if(visited[a]==true)
				continue;
			visited[a]=true;
            bool end=true;
			for(lli i=0;i<graph[a].size();i++)
			{
				lli node=graph[a][i].first;
				lli w=graph[a][i].second;
				if(visited[node]==false)
				{
					if(b+w<=dis[node])
					{
						dis[node]=b+w;
						s.push({node,dis[node]});
					}
				}
				
			}
			if(end)
            {
            	if(b==maxi)
                {
                    count++;
                }
                else if(b>maxi)
                {
                    count=1;
                    maxi=b;
                }
            }
		}
		cout<<maxi<<" "<<count<<endl;
	}
}