#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli DP[25][25];
lli graph[25][25];
int row[]={-1,1,0,0};
int col[]={0,0,-1,1};

lli solve( lli N,lli M, lli x ,lli y,lli d1, lli d2)
{
    if(x>=N || y>=M )
        return 0;
    if(x<0 || y<0)
        return 0;
    if(x==d1 && y==d2)
        return 1;
    if(DP[x][y]!=-1)
        return DP[x][y];
    lli c=1006;
    for(int i=0;i<4;i++)
    {
        if(x+row[i]>=0 && x+row[i]<N && y+col[i]>=0 && y+col[i]<M )
        {
        	cout<<x<<" "<<y<<" "<<x+row[i]<<" "<<y+col[i]<<" "<<graph[x+row[i]][y+col[i]]<<endl;
            if(graph[x+row[i]][y+col[i]]==1)
            {
                c=min(c,1+solve(N,M,x+row[i],y+col[i],d1,d2));
            }
              //  
        }
    }
    
    return DP[x][y]=c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
	    memset(DP,-1,sizeof(DP));
	    lli N,M;
	    cin>>N>>M;
	    lli y;
	    for(lli i=0;i<N;i++)
	    {
	        for(lli j=0;j<M;j++)
	        {
	            cin>>y;
	            graph[i][j]=y;
	        }
	    }
	    lli i,j;
	    cin>>i>>j;
	    if(graph[i][j]==0 || graph[0][0]==0)
	    {
	        cout<<-1<<endl;
	        continue;
	    }
	    lli x=solve(N,M,0,0,i,j);
	    if(x==1006)
	    {
	        cout<<-1<<endl;
	    }
	    else
	        cout<<x<<endl;
	}
}