// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// typedef long long int lli;

// lli count1;
// lli a[21][21];
// lli av[21][21];
// lli N;
// void solve(lli k)
// {
// 	if(k==N-1)
// 	{
// 		for(lli i=0;i<N;i++)
// 		{
// 			if(a[k][i]==1 && av[k][i]==1)
// 			{
// 				count1++;
// 			}
// 		}
// 		return ;
// 	}
// 	for(lli i=0;i<N;i++)
// 	{
// 		// if(k==0)
// 		// {
// 		// 	for(lli i=0;i<21;i++)
// 		// 	{
// 		// 		av[i]=1;
// 		// 	}
// 		// }
// 		if(a[k][i]==1 && av[k][i]==1)
// 		{
// 			for(lli j=k;j<N;j++)
// 			{
// 				av[j][i]=0;
// 			}
// 			solve(k+1);
// 			for(lli j=k;j<N;j++)
// 			{
// 				av[j][i]=1;
// 			}
// 		}
// 	}
// }



// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	lli T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		//lli N;
// 		cin>>N;
// 		count1=0;	
// 		for(lli i=0;i<N;i++)
// 		{
// 			for(lli j=0;j<N;j++)
// 			{
// 				cin>>a[i][j];
// 			}
// 		}
// 		for(lli i=0;i<21;i++)
// 		{
// 			for(lli j=0;j<21;j++)
// 			{
// 				av[i][j]=1;
// 			}
// 			//av[i]=1;
// 		}
// 		solve(0);

// 		cout<<count1<<endl;
// 	}
		
// }

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli N;
lli a[21][21];

lli allmask=0;
lli dp[1000000][21];

lli solve(lli mask, lli i)
{
	cout<<mask<<endl;
	if(mask==allmask)
		return 1;
	if(i>N)
		return 0;

	if(dp[mask][i]!=-1)
		return dp[mask][i];

	lli ways=solve(mask,i+1);

	for(lli j=0;j<N;j++)
	{
		if(a[j][i]==1)
		{
			lli x=mask & (1<<j);
			lli m=mask|(1<<j);
			//cout<<i<<" "<<j<<" "<<x<<endl;
			if(mask & (1<<j))
				continue;

			else
				ways+=solve(m, i+1);
		}
	}
	cout<<i<<" "<<mask<<" "<<ways<<endl;
	return dp[mask][i]=ways;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				cin>>a[i][j];
			}
		
		}

		allmask=(1<<N)-1;
		lli y=1<<0;
		cout<<y<<endl;
		cout<<allmask<<endl;
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<N;j++)
			{
				dp[i][j]=-1;
			}
		}

		cout<<solve(0,0)<<endl;
	}
}