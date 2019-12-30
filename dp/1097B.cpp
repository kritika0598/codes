#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli vis[20];
bool DP[20][361];
bool solve(lli Arr[], lli N, lli i, lli curAngle)
{
	if(i>=N && (curAngle%360)!=0)
	{
		return false;
	}
	if(i==N && (curAngle%360)==0)
	{
		return true;
	}
	// if(vis[i]!=-1)
	// 	return DP[i][curAngle];
	// vis[i]=0;
	lli a=curAngle-Arr[i],b=curAngle+Arr[i];
	if(curAngle-Arr[i]<0)
	{
		a=(curAngle-Arr[i]+360)%360;
	}
	if(curAngle+Arr[i]>360)
	{
		b=(curAngle+Arr[i]-360)%360;
	}
	return solve(Arr,N,i+1,a)| solve(Arr,N,i+1,b);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	memset(vis,-1,sizeof(vis));
	bool f=solve(Arr,N,0,0);
	if(f)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}		
}