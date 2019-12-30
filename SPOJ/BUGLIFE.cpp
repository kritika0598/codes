#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli colored[2005];
bool visited[2005];

bool isBipartite(vector<lli> v[], lli src) 
{ 

  
    // Assign first color to source 
    colored[src] = 1; 
  
    // Create a queue (FIFO) of vertex  
    // numbers and enqueue source vertex 
    // for BFS traversal 
    queue <lli> q; 
    q.push(src); 
  
    // Run while there are vertices  
    // in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
        lli u = q.front(); 
        q.pop(); 
  		visited[u]=true;
        // Return false if there is a self-loop    
  
        // Find all non-colored adjacent vertices 
        for (lli i = 0; i < v[u].size(); i++) 
        { 
            // An edge from u to v exists and  
            // destination v is not colored 
            if (colored[v[u][i]] == -1) 
            { 
                // Assign alternate color to this adjacent v of u 
                colored[v[u][i]] = 1 - colored[u]; 
                q.push(v[u][i]); 
            } 
  
            // An edge from u to v exists and destination  
            // v is colored with same color as u 
            else if (colored[v[u][i]] == colored[u]) 
            {
            	return false;
            }     
        } 
    } 
  
    // If we reach here, then all adjacent   
    // vertices can be colored with alternate color 
    return true; 
} 



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	lli k=1;
	while(T--)
	{
		lli N,M;
		cin>>N>>M;
		vector<lli> v[N+1];
		for(lli i=0;i<M;i++)
		{
			lli x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (lli i = 0; i <=N; ++i) 
       		 colored[i] = -1; 
       	memset(visited,false, sizeof(visited));
		cout<<"Scenario #"<<k<<":"<<endl;
		k++;
		bool flag=true;
		for(lli i=1;i<=N;i++)
		{
			if(visited[i]==false)
			{
				if(!isBipartite(v,i))
				{
					cout<<"Suspicious bugs found!"<<endl;
					flag=false;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<"No suspicious bugs found!"<<endl;
		}
	}
}