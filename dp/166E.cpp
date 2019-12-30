#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli MOD=1000000007;
lli DP[1007][4];
lli solve(lli N, lli ind, lli pos)
{
	if(pos==1 && ind==N)
	{
		return 1;
	}
	if(ind>=N)
	{
		return 0;
	}
	// if(pos==1 && ind!=0)
	// {
	// 	return 0;
	// }
	if(ind<=1000)
	{
		if(DP[ind][pos]!=-1)
		{
			return DP[ind][pos];
		}
	}
	
	if(pos==1)
	{
		if(ind<=1000)
			return DP[ind][pos] = (solve(N,ind+1,2)+solve(N,ind+1,3)+solve(N,ind+1,4))%MOD;
		return (solve(N,ind+1,2)+solve(N,ind+1,3)+solve(N,ind+1,4))%MOD;
	}
	if(pos==2)
	{
		if(ind<=1000)
			return DP[ind][pos] = (solve(N,ind+1,1)+solve(N,ind+1,3)+solve(N,ind+1,4))%MOD;
		return (solve(N,ind+1,1)+solve(N,ind+1,3)+solve(N,ind+1,4))%MOD;

	}
	if(pos==3)
	{
		if(ind<=1000)
			return DP[ind][pos]=(solve(N,ind+1,2)+solve(N,ind+1,1)+solve(N,ind+1,4))%MOD;
		return (solve(N,ind+1,2)+solve(N,ind+1,1)+solve(N,ind+1,4))%MOD;
	}
	if(pos==4)
	{
		if(ind<=1000)
			return DP[ind][pos]= (solve(N,ind+1,2)+solve(N,ind+1,3)+solve(N,ind+1,1))%MOD;

		return (solve(N,ind+1,2)+solve(N,ind+1,3)+solve(N,ind+1,1))%MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	memset(DP,-1,sizeof(DP));
	cout<<solve(N,0,1)<<endl;
}