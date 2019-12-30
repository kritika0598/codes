#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli k;
		cin>>k;
		if(k==0)
			return 0;
		string s1,s2;
		cin>>s1>>s2;

		lli n=s1.length();
		lli m=s2.length();
	//	cout<<n<<m<<endl;
		lli DP[n+1][m+1];


		for(lli i=0;i<=n;i++)
		{
			for(lli j=0;j<=m;j++)
			{
				DP[i][j]=0;
				if(i==0 || j==0)
					continue;
				lli c=1;
				while(i-c>=0 && j-c>=0 && s1[i-c]==s2[j-c])
				{
					if(c>=k)
						DP[i][j]=max(DP[i][j],c+DP[i-c][j-c]);
					c++;
				}

				DP[i][j]=max(DP[i][j],max(DP[i-1][j],DP[i][j-1]));
			}
		}

		cout<<DP[n][m]<<endl;
	}
}