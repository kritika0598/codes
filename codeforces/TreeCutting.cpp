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
	lli Arr[N+1];
	bool visited[N+1];
	memset(visited,false,sizeof(visited));
	vector<lli> v[N+1];
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		v[i].push_back(i);
	}

	for(lli i=0;i<N-1;i++)
	{
		lli x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	lli count=0;
	lli a=0,b=0,c=0;
	for(lli i=1;i<=N;i++)
	{
		if(v[i].size()>=2)
		{
			for(lli j=0;j<v[i].size();j++)
			{
				if(visited[i]==false)
				{
					if(Arr[v[i][j]]==1)
						a++;
					if(Arr[v[i][j]]==2)
						b++;
					else
						c++;
				}
				
			}
			if(a>=1 && b>=1)
				count++;
			a=0;
			b=0;
			c=0;
		}
		visited[i]=true;
	}
	if(count>1)
		cout<<0<<endl;
	else if(count==1)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<N-1<<endl;
	}
}