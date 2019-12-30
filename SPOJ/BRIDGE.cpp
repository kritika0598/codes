#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

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
		lli Arr[N];
		vector<pair<lli,lli>> v;
		lli LIS[N];
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
			LIS[i]=1;
		}
		for(lli i=0;i<N;i++)
		{
			lli x;
			cin>>x;
			v.push_back({Arr[i],x});
		}

		sort(v.begin(),v.end());
		lli maxi=1;
		for(lli i=1;i<N;i++)
		{
			for(lli j=0;j<i;j++)
			{
				if(v[i].first>=v[j].first && v[i].second >=v[j].second && LIS[i]<LIS[j]+1)
				{
					LIS[i]=LIS[j]+1;
					maxi=max(LIS[i],maxi);
				}
			}
			
		}
		cout<<maxi<<endl;
	}
}