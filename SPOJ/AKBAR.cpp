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
		lli N,R,M;
		cin>>N>>R>>M;
		vector<lli> graph[N];
		lli x,y;
		for(lli i=0;i<R;i++)
		{
			cin>>x>>y;
			graph[x-1].push_back(y-1);
			graph[y-1].push_back(x-1);
		}
		map<lli,lli> m;
		lli k,s;
		for(lli i=0;i<M;i++)
		{
			cin>>k>>s;
			queue<pair<lli,lli>> q;
			bool vis[N];
			memset(vis,false,sizeof(vis));
			q.push({k-1,0});
			while(!q.empty())
			{
				pair<lli,lli> f=q.front();
				q.pop();
				lli v=f.first;
				if(vis[v]==true)
					continue;
				vis[v]=true;
				lli l=f.second;
				//cout<<v<<" "<<l<<endl;
				if(l<s)
				{
					m[v]++;
				}
				else if(l==s)
				{
					m[v]++;
					continue;
				}
				else
				{
					continue;
				}
				for(lli j=0;j<graph[v].size();j++)
				{
					if(vis[graph[v][j]]==false)
					{
						q.push({graph[v][j],l+1});
					}
				}
			}
		}
		bool flag=true;
		for(lli i=0;i<N;i++)
		{
			if(m[i]==0)
			{
				flag=false;
				break;
			}
			if(m[i]>1)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}

	}
}