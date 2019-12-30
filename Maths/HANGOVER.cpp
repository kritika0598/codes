#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	float dp[300];
	dp[1]=0;
	memset(dp,0,sizeof(dp));
	for(lli i=1;i<300;i++)
	{
		for(float j=2;j<=i+1;j++)
		{
			dp[i]=dp[i]+(1/j);
		}

	//	cout<<i<<" "<<dp[i]<<endl;
	}

	while(1)
	{
		float x;
		cin>>x;
		if(x==0.00)
			return 0;

		cout<<lower_bound(dp,dp+300,x)-dp<<" card(s)"<<endl;
	}	
}