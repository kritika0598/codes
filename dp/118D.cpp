#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli n1,n2,k1,k2;
lli DP[105][105][2];
lli MOD=100000000;
lli solve(lli l1 , lli l2, lli prev)
{
	if(l1==0)
	{
		if(l2<=k2)
			return 1;
		else
			return 0;
	}
	if(l2==0)
	{
		if(l1<=k1)
			return 1;
		else
			return 0;
	}
	if(DP[l1][l2][prev]!=-1)
	{
		return DP[l1][l2][prev]%MOD;
	}
	lli x=0;
	if(prev==1)
	{
		for(lli i=1;i<=k2;i++)
		{
			if(l2-i<0)
				break;
			x=(x+solve(l1,l2-i,2))%MOD;
		}
	}
	else if(prev==2)
	{
		for(lli i=1;i<=k1;i++)
		{
			if(l1-i<0)
				break;
			x=(x+solve(l1-i,l2,1))%MOD;
		}
	}
	else if(prev==0)
	{
		for(lli i=1;i<=k2;i++)
		{
			if(l2-i<0)
				break;
			x=(x+solve(l1,l2-i,2))%MOD;
		}
		for(lli i=1;i<=k1;i++)
		{
			if(l1-i<0)
				break;
			x=(x+solve(l1-i,l2,1))%MOD;
		}
	}
	return DP[l1][l2][prev]=x%MOD;
	
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n1>>n2>>k1>>k2;

	memset(DP,-1,sizeof(DP));
	cout<<solve(n1,n2,0)<<endl;
}