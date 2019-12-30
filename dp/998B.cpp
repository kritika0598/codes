#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli N,B;
lli DP[105][105];
lli solve(lli E[],lli O[],lli Arr[], lli i, lli b)
{
	if(b==0)
	{
		if(E[N]-E[i]==O[N]-O[i])
		{
			return 0;
		}
		else
		{
			return INT_MIN;
		}
	}
	if(b<0)
		return INT_MIN;

	if(DP[i][b]!=-1)
		return DP[i][b];

	lli x=0;
	for(lli j=i+2;j<=N-2;j=j+2)
	{
		//if(i==0)
		{
			if(E[j]-E[i]==O[j]-O[i] && abs(Arr[j]-Arr[j+1])<=b)
			{
				//cout<<j<<endl;
				x=max(x,1+solve(E,O,Arr,j,b-abs(Arr[j]-Arr[j+1])));
			}
		}
	}

	return DP[i][b]=x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>B;
	lli Arr[N+1];
	lli E[N+1];
	lli O[N+1];
	E[0]=0;
	O[0]=0;
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		if(Arr[i]%2==0)
		{
			E[i]=E[i-1]+1;
			O[i]=O[i-1];
		}
		else
		{
			O[i]=O[i-1]+1;
			E[i]=E[i-1];
		}
	}
	if(N%2!=0)
	{
		cout<<0<<endl;
		return 0;
	}
	memset(DP,-1,sizeof(DP));
	cout<<solve(E,O,Arr,0,B)<<endl;



}