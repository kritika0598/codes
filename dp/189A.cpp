#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli n,a,b,c;
lli DP[4005];

lli solve(lli i)
{
	if(i<0)
		return INT_MIN;
	if(i==0)
	{
		return 0;
	}
	if(DP[i]!=-1)
		return DP[i];
	return DP[i]=1+max(solve(i-a),max(solve(i-b),solve(i-c)));
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>a>>b>>c;
	memset(DP,-1,sizeof(DP));
	cout<<solve(n)<<endl;

}
