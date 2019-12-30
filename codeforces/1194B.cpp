#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli q;
	cin>>q;
	while(q--)
	{
		lli n,m;
		cin>>n>>m;
		char Arr[n+1][m+1];
		map<lli,lli> r;
		map<lli,lli> c;
		for(lli i=1;i<=n;i++)
		{
			for(lli j=1;j<=m;j++)
			{
				char x;
				cin>>x;
				Arr[i][j]=x;
				if(x=='.')
				{
					r[i]++;
					c[j]++;
				}
			}
		}
		lli ans=INT_MAX;
		for(lli i=1;i<=n;i++)
		{
			for(lli j=1;j<=m;j++)
			{
				if(Arr[i][j]=='*')
				{
					ans=min(ans,r[i]+c[j]);
				}
				else
				{
					ans=min(ans,r[i]+c[j]-1);
				}
			}
		}

		cout<<ans<<endl;

	}
}