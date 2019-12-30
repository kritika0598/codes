#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


char maze[105][105];
bool visited[105][105];

lli row[]={-1,1,0,0};
lli col[]={0,0,-1,1};


lli N,M;

lli K;
lli sx,sy;
lli dfs(lli x,lli y, lli val)
{
	if(visited[x][y])
	{
		if(x==(sx-1) && y==(sy-1) && val>=K)
		{
			return 1;
		}
		return 0;
	}
	visited[x][y]=true;

	for(lli i=0;i<4;i++)
	{
		if(x+row[i]>=0 && x+row[i]<N && y+col[i]>=0 && y+col[i]<M && maze[x+row[i]][y+col[i]]!='*')
		{
			if(dfs(x+row[i],y+col[i],val+1))
				return 1;
		}
	}

	visited[x][y]=0;
	return 0;


}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>N>>M;

	cin>>K;
	cin>>sx>>sy;

	for(lli i=0;i<N;i++)
	{
		for(lli j=0;j<M;j++)
		{
			cin>>maze[i][j];
		}
	}

	memset(visited,false,sizeof(visited));

	if(dfs(sx-1,sy-1,0))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}