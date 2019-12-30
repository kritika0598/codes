#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;

	map<lli,lli> dp;

	lli Arr[n+1];

	for(lli i=1;i<=n;i++)
	{
		cin>>Arr[i];
	}
	lli ans=0;
	lli s=0;
	for(lli i=1;i<=n;i++)
	{
		dp[Arr[i]]=max(dp[Arr[i]], dp[Arr[i]-1]+1);
		if(dp[Arr[i]]>ans)
		{
			ans=dp[Arr[i]];
			s=Arr[i];
		}	
	}

	vector<lli> q;
	//queue<lli> :: iterator it;
	for(lli i=n;i>=1;i--)
	{
		if(Arr[i]==s)
		{
			q.push_back(i);
			s--;
		}
	}
	reverse(q.begin(),q.end());
	cout<<ans<<endl;
	for(auto it: q)
	{
		cout<<it<<" ";
	}

	cout<<endl;
}