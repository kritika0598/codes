/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
char Arr[101][101];
lli DP[101][101];

lli solve(lli N, lli M, lli x, lli y, vector<pair<lli,lli>> v )
{
   // cout<<x<<" "<<y<<endl;
    v.push_back({x,y});
    if(N%2==0 && M%2==0)
    {
        if(x==N/2 && y==M/2)
            return 0;
        if(x==N/2 && y==M/2+1)
            return 0;
        if(x==N/2+1 && y==M/2)
            return 0;
        if(x==N/2+1 && y==M/2+1)
            return 0;
    }
    else if(N%2!=0 && M%2!=0)
    {
        if(x==N/2+1 && y==M/2+1)
            return 0;
    }
    else if(N%2!=0 && M%2==0)
    {
        if(x==N/2+1 && y==M/2 )
            return 0;
        if(x==N/2+1 && y==M/2+1)
            return 0;
    }
    else if(N%2==0 && M%2!=0)
    {
        if(x==N/2 && y==M/2+1)
            return 0;
        if(x==N/2+1 && y== M/2+1)
            return 0;
    }
    if(DP[x][y]!=-1)
    	return DP[x][y];
    lli z=INT_MAX;
    if(x+1<=N && find(v.begin(),v.end(),make_pair(x+1,y))==v.end() && Arr[x+1][y]!='X')
        z=min(z,1+solve(N,M,x+1,y,v));
    if(x-1>=1 && find(v.begin(),v.end(),make_pair(x-1,y))==v.end() && Arr[x-1][y]!='X')
        z=min(z,1+solve(N,M,x-1,y,v));
    if(y+1<=M && find(v.begin(),v.end(),make_pair(x,y+1))==v.end() && Arr[x][y+1]!='X')
        z=min(z,1+solve(N,M,x,y+1,v));
    if(y-1>=1 && find(v.begin(),v.end(),make_pair(x,y-1))==v.end() && Arr[x][y-1]!='X')
        z=min(z,1+solve(N,M,x,y-1,v));
    return  DP[x][y]=z;
        
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
	    lli N,M;
	    cin>>N>>M;
	    lli maxi=INT_MIN;
	    lli x,y;
	    vector<pair<lli,lli>> t;
	    for(lli i=1;i<=N;i++)
	    {
	        for(lli j=1;j<=M;j++)
	        {
	            cin>>Arr[i][j];
	            if(Arr[i][j]!='X' && Arr[i][j]-'0'>maxi)
	            {
	                maxi=Arr[i][j]-'0';
	                x=i;
	                y=j;
	            }
	        }
	    }
	    for(lli i=1;i<=N;i++)
	    {
	    	for(lli j=1;j<=M;j++)
	    	{
	    		if(Arr[i][j]-'0'==maxi)
	    		{
	    			t.push_back({i,j});
	    		}
	    	}
	    }
	    
	   	
	    //memset(visited,false,sizeof(visited));
	    lli z=INT_MAX;
	    for(lli i=0;i<t.size();i++)
	    {
	    	memset(DP,-1,sizeof(DP));
	    	vector<pair<lli,lli>> v;
	    	z=min(z,solve(N,M,t[i].first,t[i].second,v));
	    }
	   //lli z=1;
	    if(z>=INT_MAX)
	        cout<<-1<<endl;
	    else
	        cout<<z<<endl;
	}
}