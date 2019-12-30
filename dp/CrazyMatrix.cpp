/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

//hackerearth
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool DP[105][105];
bool DP2[105][105];

bool vis1[105][105];
bool vis2[105][105];

lli N;
lli Arr[105][105];
bool solve(lli i,lli j)
{
    if(vis1[i][j])
        return DP[i][j];
    vis1[i][j]=true;
    if(i==N-1 && Arr[i][j]==1)
        return true;
    else if(i==N-1 && Arr[i][j]!=1)
        return false;
    if((i+1<N) &&Arr[i+1][j]==1)
    {
        DP[i][j]|=solve(i+1,j);
    }
    if((i+1<N && j-1>=0) && Arr[i+1][j-1]==1)
    {
        DP[i][j]|=solve(i+1,j-1);
    }
    if((i+1<N && j+1<N) && Arr[i+1][j+1]==1)
    {
        DP[i][j]|=solve(i+1,j+1);
    }
    return DP[i][j];    
    
}

bool solve1(lli i,lli j)
{
    if(vis2[i][j])
        return DP2[i][j];
    vis2[i][j]=true;
    if(j==N-1 && Arr[i][j]==2)
    {
        return true;
    }
    else if(j==N-1 && Arr[i][j]!=2)
    {
        return false;
    }
    
    if((i-1>=0 && j+1<N) && Arr[i-1][j+1]==2)
    {
        DP2[i][j]|=solve1(i-1,j+1);
    }
    if((i+1<N && j+1<N)&& Arr[i+1][j+1]==2)
    {
        DP2[i][j]|=solve1(i+1,j+1);
    }
    if((j+1<N) && Arr[i][j+1]==2)
    {
        DP2[i][j]|=solve1(i,j+1);
    }
    
    return DP2[i][j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	

	bool f1=false;
	bool f2=false;
	lli c1=0,c2=0;
	memset(DP,false,sizeof(DP));
	memset(DP2,false,sizeof(DP2));
	memset(vis1,false,sizeof(vis1));
	memset(vis2,false,sizeof(vis2));
	for(lli i=0;i<N;i++)
	{
	    for(lli j=0;j<N;j++)
	    {
	        cin>>Arr[i][j];

	    }
	}
	
	for(lli i=0;i<N;i++)
	{
	    for(lli j=0;j<N;j++)
	    {
	        if(Arr[i][j]==1)
	        {
	            c1++;
	            break;
	        }
	    }
	}
	
	for(lli i=0;i<N;i++)
	{
	    for(lli j=0;j<N;j++)
	    {
	        if(Arr[j][i]==2)
	        {
	            c2++;
	            break;
	        }
	    }
	}
	
    for(lli i=0;i<N;i++)
    {
        if(solve(0,i))
        {
            f1=true;
            break;
        }
    }
    
    for(lli i=0;i<N;i++)
    {
        if(solve1(i,0))
        {
            f2=true;
            break;
        }
    }
    
    if(f1 && f2)
    {
        cout<<"AMBIGUOUS"<<endl;
    }
    else if(f1)
    {
        cout<<1<<endl;
    }
    else if(f2)
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
}