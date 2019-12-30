#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

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
		vector<pair<lli,lli>> graph[N+1];
		for(lli i=0;i<N-1;i++)
		{
			lli x,y,d;
			cin>>x>>y>>d;
			graph[x].push_back({y,d});
			graph[y].push_back({x,d});
		}

		lli maxi=0;
		stack<pair<lli,lli>> s;
		s.push({1,0});
		lli dis[N+1];
			for(lli j=1;j<=N;j++)
			{
				dis[j]=100000005;
			}
			//dis[i]=0;
			//cout<<i<<endl;
			while(!s.empty())
			{
				pair<lli,lli> p=s.top();
				s.pop();
				lli x=p.first;
				lli d=p.second;
				//cout<<x<<" "<<d<<endl;
				if(dis[x]<d)
					continue;
				dis[x]=d;
				if(dis[x]>maxi)
					maxi=dis[x];
				for(lli j=0;j<graph[x].size();j++)
				{
					pair<lli,lli> f=graph[x][j];
					if(dis[f.first]>dis[x]+f.second)
					{
						s.push({f.first,dis[x]+f.second});
						dis[f.first]=dis[x]+f.second;
					}
				}

			}
		lli k;
		for(lli i=1;i<=N;i++)
		{
			if(dis[i]>=maxi)
			{
				k=i;
			}
		}
	//	s.clear();
		s.push({k,0});
			for(lli j=1;j<=N;j++)
			{
				dis[j]=100000005;
			}
			//dis[i]=0;
			//cout<<i<<endl;
			while(!s.empty())
			{
				pair<lli,lli> p=s.top();
				s.pop();
				lli x=p.first;
				lli d=p.second;
				//cout<<x<<" "<<d<<endl;
				if(dis[x]<d)
					continue;
				dis[x]=d;
				if(dis[x]>maxi)
					maxi=dis[x];
				for(lli j=0;j<graph[x].size();j++)
				{
					pair<lli,lli> f=graph[x][j];
					if(dis[f.first]>dis[x]+f.second)
					{
						s.push({f.first,dis[x]+f.second});
						dis[f.first]=dis[x]+f.second;
					}
				}

			}

			cout<<maxi<<endl;
		
	}		
}