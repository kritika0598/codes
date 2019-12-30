#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool visited[100005];
map<lli,lli> level;
map<lli,lli> ::iterator itr;
double a=0;
// void dfs(vector<lli> graph[], lli src)
// {
// 	stack<pair<lli,lli>> st;
// 	st.push({src,0});
// 	while(!st.empty())
// 	{
// 		pair<lli,lli> p = st.top();
// 		st.pop();
// 		lli x=p.first;
// 		lli l=p.second;
// 		if(visited[x])
// 			continue;
// 		visited[x]=true;
// 		bool flag=true;
// 		for(lli i=0;i<graph[x].size();i++)
// 		{
// 			if(!visited[graph[x][i]])
// 			{
// 				flag=false;
// 				st.push({graph[x][i],l+1});
// 			}
// 		}
// 		if(flag)
// 		{
// 			level[l]++;
// 			a++;
// 		}
// 	} 
// }

double dfs(vector<lli> graph[], lli src)
{
	visited[src]=true;
	double k;
	if(src==1)
	{
		k=graph[src].size();
	}
	else
	{
		k=graph[src].size()-1;
	}
	if(k==0)
		return 0;
	double x=0;
	for(lli i=0;i<graph[src].size();i++)
	{
		if(visited[graph[src][i]]==false)
		{
			x+=dfs(graph,graph[src][i]);
		}
	}
	return (x/k)+1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	if(N==1)
	{
		cout<<"0.000000000000000"<<endl;
		return 0;
	}
	vector<lli> graph[N+1];
	lli u,v;
	for(lli i=0;i<N-1;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(visited,false,sizeof(visited));

	cout<<fixed<<setprecision(15)<<dfs(graph,1)<<endl;
// 	double x=0;

// 	for(itr=level.begin();itr!=level.end();itr++)
// 	{
// 		x+=((itr->first)*(itr->second));
// 	}

// //	cout<<a<<" "<<x<<endl;
// 	double ans=(x/a);
// 	cout<<fixed<<setprecision(15)<<ans<<endl;
}