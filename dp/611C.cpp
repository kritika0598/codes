#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli h,w;
	cin>>h>>w;

	char A[h][w];
	char x;
	for(lli i=0;i<h;i++)	
	{
		for(lli j=0;j<w;j++)
		{
			cin>>A[i][j];
		}
	}

	lli histR[h][w];
	memset(histR,0,sizeof(histR));
	for(lli i=0;i<h;i++)
	{
		for(lli j=0;j<w-1;j++)
		{
			for(lli k=j;k<w-1;k++)
			{
				if(A[i][k]=='.' && A[i][k+1]=='.')
				{
					histR[i][j]++;
				}
			}
		}
	}

	lli histC[h][w];
	memset(histC,0,sizeof(histC));
	for(lli j=0;j<w;j++)
	{
		for(lli i=0;i<h-1;i++)
		{
			for(lli k=i;k<h-1;k++)
			{
				if(A[k][j]=='.' && A[k+1][j]=='.')
				{
					histC[i][j]++;
				}
			}
		}
	}

	lli Q;
	cin>>Q;
	while(Q--)
	{
		lli r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		r1--;
		r2--;
		c1--;
		c2--;
		//cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
		lli ans=0;
		//cout<<"colum sum"<<endl;
		for(lli i=r1;i<=r2;i++)
		{
			ans+=(histR[i][c1]-histR[i][c2]);
		//	cout<<i<<" "<<histR[i][c1]<<" "<<histR[i][c2]<<endl;
		}
		//cout<<"row sum"<<endl;
		for(lli j=c1;j<=c2;j++)
		{
			ans+=(histC[r1][j]-histC[r2][j]);
		//	cout<<j<<" "<<histC[r1][j]<<" "<<histC[r2][j]<<endl;
		}

		cout<<ans<<endl;
		
	}
}