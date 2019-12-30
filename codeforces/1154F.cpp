// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// typedef int lli;

// lli compare(pair<lli,lli> a, pair<lli,lli> b)
// {
// 	if(a.first==b.first)
// 	{
// 		return(a.second>b.second);
// 	}
// 	return(a.first<b.first);
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	lli N,M,K;
// 	cin>>N>>M>>K;
// 	lli ans=0;
// 	vector<lli> Arr;
// 	vector<pair<lli,lli>> offers;
// 	lli x;
// 	for(lli i=0;i<N;i++)
// 	{
// 		cin>>x;
// 		Arr.push_back(x);
// 	}
// 	sort(Arr.begin(),Arr.end());

// 	x=N-K;

// 	Arr.erase(Arr.begin()+K,Arr.end());
// 	// cout<<endl;
// 	// for(lli i=0;i<Arr.size();i++)
// 	// {
// 	// 	cout<<Arr[i]<<" ";
// 	// }
// 	// cout<<endl;
// 	vector<lli> cum;
// 	cum.push_back(Arr[0]);
// 	for(lli i=1;i<Arr.size();i++)
// 	{
// 		cum.push_back(cum[i-1]+Arr[i]);
// 	}
// 	lli y;

// 	for(lli i=0;i<M;i++)
// 	{
// 		cin>>x>>y;
// 		if(x>K)
// 			continue;
// 		offers.push_back(make_pair(x-y,x));
// 	}
// 	if(offers.size()==0)
// 	{
// 		cout<<cum[cum.size()-1];
// 		return 0;
// 	}
// 	sort(offers.begin(),offers.end(),compare);

// 	// for(lli i=0;i<offers.size();i++)
// 	// {
// 	// 	cout<<offers[i].first<<" "<<offers[i].second<<endl;
// 	// }
// 	while(!cum.empty())
// 	{
// 		if(offers[0].second>cum.size())
// 			break;
// 		{
// 			ans=ans+(cum[cum.size()-1]-cum[cum.size()-offers[0].first-1]);
// 		}		
// 		cum.erase(cum.begin()+cum.size()-offers[0].second,cum.end());
// 		offers.erase(offers.begin());

// 	}

// 	if(!cum.empty())
// 	{
// 		ans+=cum[cum.size()-1];
// 	}

// 	cout<<ans<<endl;
// 	return 0;

// }


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M,K;
	cin>>N>>M>>K;

	vector<lli> a(N);
	lli c;
	for(lli i=0;i<N;i++)
	{
		cin>>c;
		a[i]=c;
	}

	sort(a.begin(),a.end());
	a.resize(K);

	reverse(a.begin(),a.end());

	vector<lli> que(K+1);
	lli x,y;
	for(lli i=0;i<M;i++)
	{
		cin>>x>>y;
		if(x<=K)
		{
			que[x]=max(que[x],y);
		}
	}

	vector<lli> cum(K+1);
	for(lli i=0;i<K;i++)
	{
		cum[i+1]=cum[i]+a[i];
	}

	vector<lli> dp(K+1, 1000000005);
	dp[0]=0;
	for(lli i=0;i<K;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+a[i]);

		for(lli j=1;j<=K;j++)
		{
			if(que[j]==0)
				continue;
			if(i+j>K)
				break;
			dp[i+j]=min(dp[i+j],dp[i]+cum[i+j-que[j]]-cum[i]);
		}
	}

	cout<<dp[K]<<endl;
	return 0;
}