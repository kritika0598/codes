#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
bool flag=false;

lli DP[100005][10];

bool cmp(pair<lli,lli> a, pair<lli,lli> b)
{
	if(a.first==b.first)
		return a.second<b.second;
	return a.first<b.first;
}

lli solve(vector<pair<lli,lli>> box[], lli i , lli N, lli prev)
{
	//cout<<i<<" "<<N<<" "<<prev<<endl;
	if(i>N)
	{
		flag=true;
		return 0;
		
	}
	if(DP[i][prev]!=-1)
		return DP[i][prev];
	lli x=0;
	lli p=box[i].size();
//	cout<<x<<endl;
	for(lli j=0;j<p;j++)
	{
		if(box[i][j].first!=prev)
		{
			x=max(x,box[i][j].second+solve(box,i+1,N,box[i][j].first));
		}
	}
	//cout<<x<<endl;
	return DP[i][prev]= x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,M;
		cin>>N>>M;
		vector<pair<lli,lli>> box[N+1];
		for(lli i=0;i<M;i++)
		{
			lli b,c,v;
			cin>>b>>c>>v;
			bool f=true;
			for(lli j=0;j<box[b].size();j++)
			{
				if(box[b][j].first==c)
				{
					if(box[b][j].second<v)
					{
						box[b].erase(box[b].begin()+j);
						
					}
					else
					{
						f=false;
					}
					break;
				}

			}
			if(f)
			{
				box[b].push_back({c,v});
			}
			
		}
		// for(lli i=1;i<=N;i++)
		// {
		// 	for(lli j=0;j<box[i].size();j++)
		// 	{
		// 		cout<<box[i][j].first<<" "<<box[i][j].second<<" ";
		// 	}
		// 	cout<<endl;
		// }
		lli x=-1;
		flag=false;
		memset(DP,-1,sizeof(DP));
		for(lli i=0;i<box[1].size();i++)
		{	
			x=max(x,box[1][i].second+solve(box,2,N,box[1][i].first));
		}
		if(flag)
		{
			cout<<x<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}

	}	
}