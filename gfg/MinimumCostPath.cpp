#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli DP[55][55];

void solve(lli N,lli i, lli j, vector<lli> Arr[],lli val)
{
    if(i>=N || j>=N)
        return ;
    if(DP[i][j]<=val+Arr[i][j])
    	return ;
    //lli c=INT_MAX;
    DP[i][j]=val+Arr[i][j];
    //cout<<i<<" "<<j<<" "<<DP[i][j]<<endl;
    if(i==N-1 && j==N-1)
    	return ;
    if(i-1>=0 && j<N && j>=0 && i-1<N && DP[i-1][j]>val+Arr[i][j]+Arr[i-1][j])
    {
        //cout<<i<<" "<<j<<" "<<i-1<<" "<<j<<endl;
        solve(N,i-1,j,Arr,val+Arr[i][j]);
    }
    if(j-1>=0 && i>=0 && i<N && j-1<N && DP[i][j-1]>val+Arr[i][j]+Arr[i][j-1])
    {
        //cout<<i<<" "<<j<<" "<<i<<" "<<j-1<<endl;
        solve(N,i,j-1,Arr,val+Arr[i][j]);
    }
    if(j+1<N && i>=0 && i<N &&  j+1>=0 && DP[i][j+1]>val+Arr[i][j]+Arr[i][j+1])
    {
        //cout<<i<<" "<<j<<" "<<i<<" "<<j+1<<endl;
        solve(N,i,j+1,Arr,val+Arr[i][j]);
    }
    if(i+1<N && j>=0 && j<N && i+1>=0 && DP[i+1][j]>val+Arr[i][j]+Arr[i+1][j])
    {
       // cout<<i<<" "<<j<<" "<<i+1<<" "<<j<<endl;
        solve(N,i+1,j,Arr,val+Arr[i][j]);
    }    
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
	    lli N;
	    cin>>N;
	    vector<lli> Arr[N];
	    lli x;
	    for(lli i=0;i<N;i++)
	    {
	        for(lli j=0;j<N;j++)
	        {
	            cin>>x;
	            Arr[i].push_back(x);
	            DP[i][j]=10000005;
	        }
	    }
	    solve(N,0,0,Arr,0);
	    cout<<DP[N-1][N-1]<<endl;
	}
}