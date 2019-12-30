#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[20][20];

void flip(lli i, lli j, lli m, lli n)
{
	Arr[i][j]=!Arr[i][j];
	if(i-1>=0)
		Arr[i-1][j]=!Arr[i-1][j];
	if(i+1<n)
		Arr[i+1][j]=!Arr[i+1][j];
	if(j+1<m)
		Arr[i][j+1]=!Arr[i][j+1];
	if(j-1>=0)
		Arr[i][j-1]=!Arr[i][j-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m;
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0)
			return 0;
		for(lli i=0;i<n;i++)
		{
			string x;
			cin>>x;
			for(lli j=0;j<m;j++)
			{
				if(x[j]=='X')
				{
					Arr[i][j]=0;
				}
				else
				{
					Arr[i][j]=1;
				}
			}
		}
		bool f=true;
		lli dummy[n][m];
		for(lli i=0;i<n;i++)
		{
			for(lli j=0;j<m;j++)
			{
				dummy[i][j]=Arr[i][j];
			}
		}
		lli ans=INT_MAX;
		for(lli k=0;k<(1<<m);k++)
		{
			for(lli i=0;i<n;i++)
			{
				for(lli j=0;j<m;j++)
				{
					Arr[i][j]=dummy[i][j];
				}
			}
			lli temp=0;
			for(lli i=0;i<m;i++)
			{
				if(k&(1<<i))
				{
					flip(0,i,m,n);
					temp++;
				}
			}
			for(lli i=1;i<n;i++)
			{
				for(lli j=0;j<m;j++)
				{
					if(Arr[i-1][j]==0)
					{
						flip(i,j,m,n);
						temp++;
					}
				}
			}

			bool flag=true;
			for(lli i=0;i<n;i++)
			{
				for(lli j=0;j<m;j++)
				{
					if(Arr[i][j]==0)
					{
						flag=false;
						break;
					}
				}
			}
			if(flag)
			{
				f=false;
				ans=min(ans,temp);
				//break;
			}
		}

		if(f)
		{
			cout<<"Damaged billboard."<<endl;
		}
		else
		{
			cout<<"You have to tap "<<ans<<" tiles."<<endl;
		}
	}	
}