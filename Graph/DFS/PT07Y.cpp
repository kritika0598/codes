#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
bool visited[10005];
vector<lli> v[10005];

void dfs(lli s)
{
	visited[s]=true;
	for(lli i=0;i<v[s].size();i++)
	{
		if(visited[v[s][i]]==false)
		{
			dfs(v[s][i]);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	lli connected_component=0;
	memset(visited,false,sizeof(visited));
	cin>>N>>M;
	if(M!=N-1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		lli x,y;
		for(lli i=0;i<M;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
		}
		for(lli i=1;i<=N;i++)
		{
			if(visited[i]==false)
			{
				dfs(i);
				connected_component++;
			}	
		}
		if(connected_component>1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}

	return 0;	

}