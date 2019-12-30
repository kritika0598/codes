#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
vector<lli> v[10005];
bool visited[100005];
//vector<lli> level[100005];
map<lli,lli> level;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	for(lli i=1;i<N;i++)
	{
		lli x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));

	lli ans=1;
	// for(lli i=1;i<=N;i++)
	// {
	// 	if(visited[i]==false)
	// 	{
	// 		ans=max(dfs(i),ans);
	// 	}
	// }

	//stack<lli> s;
	queue<lli> q;
	q.push(1);
	level[1]=1;
	lli last=1;
	visited[1]=true;
//	lli z=1;
	bool flag=false;
	while(q.size()!=0)
	{
		lli d=q.front();
	//	cout<<z<<" "<<d<<endl;
		q.pop();
		flag=false;
		for(lli i=0;i<v[d].size();i++)
		{

			if(visited[v[d][i]]==false)
			{
				//cout<<v[d][i]<<" "<<z<<endl;
			//	level[z]++;
				level[v[d][i]]=level[d]+1;
				if(level[v[d][i]]>ans)
				{
					ans=level[v[d][i]];
					last=v[d][i];
				}	
				q.push(v[d][i]);
				visited[v[d][i]]=true;
				//flag=true;
			}
		}
		
	}

	ans=1;
	//memset(level,0,sizeof(level));
	level.clear();
	q.push(last);
	level[last]=1;
	//lli last=1;
	memset(visited,false,sizeof(visited));
	visited[last]=true;
//	lli z=1
	while(q.size()!=0)
	{
		lli d=q.front();
	//	cout<<z<<" "<<d<<endl;
		q.pop();
		flag=false;
		for(lli i=0;i<v[d].size();i++)
		{

			if(visited[v[d][i]]==false)
			{
				//cout<<v[d][i]<<" "<<z<<endl;
			//	level[z]++;
				level[v[d][i]]=level[d]+1;
				if(level[v[d][i]]>ans)
				{
					ans=level[v[d][i]];
				//	last=v[d][i];
				}	
				q.push(v[d][i]);
				visited[v[d][i]]=true;
				//flag=true;
			}
		}
		
	}

//	cout<<last<<endl;
	cout<<ans-1<<endl;

}