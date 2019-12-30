#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Arr[25][25];
lli N,M;
lli DP[25][25];

lli solve(lli x,lli y)
{
	if(x==N && y==M)
		return DP[x][y]=Arr[N][M];
	if(DP[x][y]!=-1)
		return DP[x][y];
	if(x>N || y>M)
		return INT_MAX; 
	else
	{	
		return DP[x][y]=min(Arr[x][y]+solve(x+1,y), Arr[x][y]+solve(x,y+1));

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	lli X,Y;
	cin>>X>>Y;

	for(lli i=1;i<=N;i++)
	{
		for(lli j=1;j<=M;j++)
		{
			cin>>Arr[i][j];
		}
	}

	for(lli i=0;i<25;i++)
	{
		for(lli j=0;j<25;j++)
		{
			DP[i][j]=-1;
		}
	}
	lli ans=solve(X,Y);

	ans-=Arr[X][Y];

	if(Arr[X][Y]-ans>=0)
		cout<<"Y "<<Arr[X][Y]-ans<<endl;
	else
		cout<<"N"<<endl;
}