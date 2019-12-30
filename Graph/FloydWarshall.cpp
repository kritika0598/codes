#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli MAX=1000;

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

		lli adj[N][N];
		string s;
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				cin>>s;
				if(s=="INF")
				{
					adj[i][j]=1000;
				}
				else
				{
					adj[i][j]=stoi(s);
				}
			}
			
		}

		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				for(lli k=0;k<N;k++)
				{
					if(k!=i)
					{
						if(adj[i][j]>adj[i][k]+adj[k][j])
						{
							adj[i][j]=adj[i][k]+adj[k][j];
						}
					}
					
				}
			}
		}

		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}
	}	
}