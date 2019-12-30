#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pi;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	lli Arr[N];
	lli A[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	priority_queue<pi, vector<pi>, greater<pi> > pq;
	lli x;
	for(lli i=0;i<N;i++)
	{
		cin>>x;
		A[i]=x;
		pq.push(make_pair(x,i));
	}
	bool CD[N];
	memset(CD,false,sizeof(CD));
	for(lli i=0;i<M;i++)
	{
		lli u,v;
		lli ans=0;
		cin>>u>>v;
		u--;
		if(v<=Arr[u])
		{
			Arr[u]=Arr[u]-v;
			ans=ans+(v*A[u]);
			if(Arr[u]==0)
			{
				CD[u]=true;
			}
		}
		else
		{
			ans=ans+(Arr[u]*A[u]);
			v=v-Arr[u];
			Arr[u]=0;			
			while(v!=0)
			{
				if(pq.empty())
				{
					ans=0;
					break;
				}
				if(CD[pq.top().second]==true)
				{
					pq.pop();
				}
				else
				{
					if(Arr[pq.top().second]>=v)
					{
						ans=ans+(v*A[pq.top().second]);
						Arr[pq.top().second]-=v;
						v=0;
						if(Arr[pq.top().second]==0)
						{
							CD[pq.top().second]=true;
							pq.pop();
						}
					}
					else
					{
						ans=ans+(Arr[pq.top().second]*A[pq.top().second]);
						v=v-Arr[pq.top().second];
						Arr[pq.top().second]=0;
						CD[pq.top().second]=true;
						pq.pop();

					}
				}
			}

		}

		cout<<ans<<endl;
	}
}