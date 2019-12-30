//solved by girl int the night hackerearth


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		

	lli N,M;
	cin>>N>>M;

	lli Arr[N+1][M+1];
	lli DP[N+1][M+1][26];
	char c;
	for(lli i=1;i<=N;i++)
	{
		for(lli j=1;j<=M;j++)
		{
			cin>>c;
			Arr[i][j]=c-'a';
		}
	}

	for(lli i=0;i<=N;i++)
	{
		for(lli j=0;j<=M;j++)
		{
			for(lli k=0;k<26;k++)
			{
				DP[i][j][k]=0;
			}
		}
	}
	bool flag=false;
	for(lli i=1;i<=N;i++)
	{
		for(lli j=1;j<=M;j++)
		{
			if(i==1 && j==1)
			{
				DP[i][j][Arr[i][j]]++;
			}
			else
			{
				for(lli k=0;k<26;k++)
				{
					if(DP[i-1][j][k]==DP[i][j-1][k])
						continue;
					else if(DP[i-1][j][k]>DP[i][j-1][k])
					{
						flag=true;
						break;
					}
					else
					{
						flag=false;
						break;
					}
				}

				if(flag)
				{
					for(lli k=0;k<26;k++)
					{
						DP[i][j][k]=DP[i-1][j][k];
					}
				}
				else
				{
					for(lli k=0;k<26;k++)
					{
						DP[i][j][k]=DP[i][j-1][k];
					}
				}

				DP[i][j][Arr[i][j]]++;
			}
		}
	}

	for(lli i=0;i<26;i++)
	{
		while(DP[N][M][i]--)
		{
			char c='a'+i;
			cout<<c;
		}
	}
	cout<<endl;
}