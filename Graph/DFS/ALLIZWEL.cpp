#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

char Arr[105][105];
bool visited[105][105];
lli N,M;

lli row[8] = {0, 0, 1, -1, 1, 1, -1, -1};
lli col[8] = {1, -1, 0, 0, 1, -1, 1, -1};

char pattern[11]={'A','L','L','I','Z','Z','W','E','L','L'};


lli dfs(lli x,lli y,lli ind)
{
	if(ind==9)
		return 1;
	//if(!visited[x][y])
	{
		visited[x][y]=true;
		for(lli i=0;i<8;i++)
		{
			if(x+row[i]>=0 && x+row[i]<N && y+col[i]>=0 && y+col[i]<M)
			{
				if(Arr[x+row[i]][y+col[i]]==pattern[ind+1] && !visited[x+row[i]][y+col[i]])
				{
					visited[x+row[i]][y+col[i]]=true;
					if(dfs(x+row[i],y+col[i],ind+1))
						return 1;

					visited[x+row[i]][y+col[i]]=false;
				}
			}
		}

	}

	visited[x][y]=false;
	return 0;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		//lli N,M;
		memset(visited,false,sizeof(visited));
		cin>>N>>M;
		vector<pair<lli,lli>> v;
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<M;j++)
			{
				cin>>Arr[i][j];
				if(Arr[i][j]=='A')
				{
					v.push_back(make_pair(i,j));
				}
			}
		}
		bool flag=true;

		//cout<<v.size()<<endl;

		if(v.size()==0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			for(lli i=0;i<v.size();i++)
			{
				if(dfs(v[i].first,v[i].second,0))
				{
					cout<<"YES"<<endl;
					flag=false;
					break;
				}	
			}
		}

		if(flag)
		{
			cout<<"NO"<<endl;
		}

	}
}