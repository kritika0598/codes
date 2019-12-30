#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;
	lli arr[n];
	map<lli,lli> m;
	set<lli>s;
	lli ans[n];
	vector<lli>ind[5000];
	if(n<k)
	{
		cout<<"NO"<<endl;
		return 0;
	}	
	for(lli i=0;i<n;i++)
	{
		cin>>arr[i];
		m[arr[i]]++;
		ind[arr[i]].push_back(i);
		s.insert(arr[i]);
	}
	sort(arr,arr+n);
	lli st=1;
	lli x;
	ans[0]=1;
	lli ns[n];
	lli t=1;
	for(lli i=0;i<ind[arr[0]].size();i++)
	{
		ns[ind[arr[0]][i]]=t;
		if(t>k)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		t++;
	}
//	ns[ind[arr[0]][0]]=1;
	for(lli i=m[arr[0]];i<n;i++)
	{
		if(arr[i]==arr[i-1])
		{
			ans[i]=ans[i-1]+1;
			ns[ind[arr[i]][0]]=ans[i];
			ind[arr[i]].erase(ind[arr[i]].begin());
			if(ans[i]>k)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			if(st<ans[i])
				st=ans[i];
		}
		else
		{
			ans[i]=1;
			ns[ind[arr[i]][0]]=ans[i];
			ind[arr[i]].erase(ind[arr[i]].begin());
		}
	}

	lli dif=st-k;
	if(t-1>st)
		st=t-1;
	if(st<k)
	{
		//for(lli i=n-1;i>=n-1-dif;i--)
		lli i=n-1;
		while(k!=1)
		{
			ns[i]=k;
			k--;
			i--;
			if(i<0)
			{
				cout<<"NO"<<endl;
				return 0;
			}

		}
		//ans[]
	}

	cout<<"YES"<<endl;
	for(lli i=0;i<n;i++)
	{
		cout<<ns[i]<<" ";
	}
	cout<<endl;
}