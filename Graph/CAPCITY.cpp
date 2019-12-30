#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;

	set<lli> graph[N+1];
	set<lli> :: iterator itr;
	set<lli> graph1[N+1];
	lli x,y;
	for(lli i=0;i<M;i++)
	{
		cin>>x>>y;
		graph[y].insert(x);
		graph1[y].insert(x);
	}
	lli cnt=0;
	vector<lli> v;
	for(lli i=1;i<=N;i++)
	{
		for(lli j=1;j<=N;j++)
		{
			itr=find(graph1[j].begin(),graph1[j].end(),j);
			if(itr!=graph1[j].end())
				graph1[j].erase(itr);
			if(graph1[j].size()<N-1)
			{
				for(itr=graph1[j].begin();itr!=graph1[j].end();itr++)
				{
					graph1[j].insert(graph1[*itr].begin(),graph1[*itr].end());
				}
				//graph1[i].insert(graph1[i].begin(),graph[i].end());
				itr=find(graph1[j].begin(),graph1[j].end(),j);
				if(itr!=graph1[j].end())
					graph1[j].erase(itr);
				if(graph1[j].size()>=N-1)
				{
					cnt++;
					v.push_back(j);
				}
			}
			
			//graph1[i].insert(graph1[i].begin(),graph1[i].end());
		}
		
	}
	
			
	cout<<v.size()<<endl;
	sort(v.begin(),v.end());
	for(lli i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;



}