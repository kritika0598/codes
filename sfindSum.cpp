#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long lli;

vector <lli> graph[100000]; //Vector for maintaining adjacency list explained above
lli level[100000]; //To determine the level of each node
bool vis[100000]; //Mark the node if visited 


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n, a, b;
	cin>>n;

	vector<lli> v[n+1];
	vector<lli> parent[n+1];
	for(lli i=0;i<n-1;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		parent[b].push_back(a);
		graph[a].push_back(b);
		//graph[b].push_back(a);
	}

	queue<lli> q;
	vector<lli> final[n+1];
	lli Arr[n+1];
	memset(Arr,0,sizeof(Arr));
	for(lli i=1;i<=n;i++)
	{
		if(v[i].size()==0)
		{
			q.push(i);
			final[i].push_back(parent[i][0]);
		}
	}

	while(!q.empty())
	{
		//cout<<"hello"<<endl;
		lli x=q.front();
		q.pop();
		if(parent[x].size()!=0)
		{
			Arr[parent[x][0]]=max(Arr[parent[x][0]], Arr[x]+1);
			q.push(parent[x][0]);
		}
	}
	lli s=1;
    queue <int> qu;
    qu.push(s);
    level[ 1 ] = 0 ;  //Setting the level of the source node as 0
    vis[ s ] = true;
    int z=1;
    while(!qu.empty())
    {
        lli p = qu.front();
        qu.pop();
            
        for(lli i = 0;i < graph[ p ].size() ; i++)
        {
            if(vis[ graph[ p ][ i ] ] == false)
            {
            //Setting the level of each node with an increment in the level of parent node
                level[graph[p][i]]=level[p]+1;                 
                qu.push(graph[ p ][ i ]);
                vis[ graph[ p ][ i ] ] = true;
              
            }
           
        }
        // z++;
    }




    vector<lli> :: iterator itr;
	for(lli i=1; i<=n;i++)
	{
		if(final[i].size()!=0)
		{
			itr=final[i].begin();
			//cout<<*itr<<endl;
			while(itr!=final[i].end())
			{
				if(parent[*itr].size()==0)
					break;
				if(parent[*itr].size()!=0)
					final[i].push_back(parent[*itr][0]);
				itr++;
					//cout<<"hello1"<<endl;
			}
		}

		// cout<<i<<" "<<endl;
		// cout<<"printing parents"<<endl;
		// for(itr=final[i].begin();itr!=final[i].end();itr++)
		// {
		// 	cout<<*itr<<endl;
		// }
	}
	//cout<<"hello2"<<endl;
	lli ans[n+1];

	memset(ans,0,sizeof(ans));

	for(lli i=1;i<=n;i++)
	{
		if(final[i].size()!=0)
		{
			final[i].push_back(i);
			for(itr=final[i].begin(); itr!=final[i].end();itr++)
			{
				//cout<<i<<" "<<*itr<<" "<<Arr[*itr]<<" "<<level[i]-level[*itr]<<endl;
				if(Arr[*itr]== (level[i]-level[*itr]))
				{
					if(parent[*itr].size()!=0)
						ans[parent[*itr][0]]++;
				}
			}

		}
	}

	// for(lli i=1;i<=n;i++)
	// {
	// 	cout<<level[i]<<" ";
	// }

	// cout<<endl;

	for(lli i=1;i<n;i++)
	{
		if(final[i].size()!=0)
			cout<<1<<" ";
		else
			cout<<ans[i]<<" ";
	}
	if(final[n].size()!=0)
			cout<<1;
	else
		cout<<ans[n];

}

