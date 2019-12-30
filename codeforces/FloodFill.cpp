#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	vector<lli> v;
	vector<lli> v1;
	map<lli,lli> m;
	map<lli,lli> :: iterator itr;
	lli x;
	lli k=0;
	for(lli i=0;i<N;i++)
	{
		cin>>x;
		if(i==0)
		{
			v.push_back(x);
		//	cout<<x<<endl;
			k++;
		}	
		else
		{
			if(v[k-1]!=x)
			{
				v.push_back(x);
			//	cout<<x<<endl;
				k++;
			}
		}
	}
	//lli j=0;
	k=0;
	//cout<<v.size()<<endl;
	for(lli i=v.size()-1;i>=0;i--)
	{
		v1.push_back(v[i]);
		m[v[i]]++;
	//	cout<<v1[k]<<endl;
		k++;
	}
	lli n=v.size();
	lli DP[v.size()+1][v1.size()+1];

	for(lli i=0;i<=n;i++)
	{
		for(lli j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				DP[i][j]=0;
			}
			else
			{
				if(v[i-1]==v1[j-1])
				{
					DP[i][j]=DP[i-1][j-1]+1;
				}
				else
				{
					DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
				}	

			}
		}
	}
	lli maxi=0;
	// for(itr=m.begin();itr!=m.end();itr++)
	// {
	// 	if(itr->second>maxi)
	// 		maxi=itr->second;
	// }

	lli ans= n-(DP[n][n]+1)/2;
	//cout<<v.size()<<endl;
	cout<<ans<<endl;


}