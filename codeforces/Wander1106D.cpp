#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool visited[100005];
priority_queue <lli, vector<lli>, greater<lli>> gl;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	vector<lli> v[100005];

	for(lli i=0;i<M;i++)
	{
		lli x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	// for(lli i=1;i<=N;i++)
	// {
	// 	sort(v[i].begin(),v[i].end());
	// }

	memset(visited,false,sizeof(visited));

	//cout<<1<<" ";

	gl.push(1);
	visited[1]=true;
	while(!gl.empty())
	{
		lli x;
	//	gl.sort();
		//sort(gl.begin(),gl.end());
		// if(gl.front()>gl.back())
		// {
		// 	x=gl.back();
		// 	gl.pop_back();
		// 	cout<<x<<" ";
		// }
	//	else
		{
			x=gl.top();
			gl.pop();
			cout<<x<<" ";
		}
		for(lli i=0;i<v[x].size();i++)
		{
			if(!visited[v[x][i]])
			{
				gl.push(v[x][i]);
				visited[v[x][i]]=true;
			}
		}

	}


}