// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// typedef long long int lli;

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	while(1)
// 	{
// 		lli N;
// 		cin>>N;
// 		if(N==-1)
// 		{
// 			return 0;
// 		}

// 		lli Arr[N];
// 		for(lli i=0;i<N;i++)
// 		{
// 			cin>>Arr[i];
// 		}

// 		lli lis[N];
// 		for(lli i=0;i<N;i++)
// 		{
// 			lis[i]=1;
// 		}

// 		lli maxi=1;
// 		lli z=0;
// 		for(lli i=1;i<N;i++)
// 		{
// 			for(lli j=0;j<i;j++)
// 			{
// 				if(Arr[j]<Arr[i])
// 				{
// 					if(lis[i]<lis[j]+1)
// 					{
// 						lis[i]=lis[j]+1;
// 						if(lis[i]>maxi)
// 						{
// 							maxi=lis[i];
// 							z=i;
// 						}	
// 					}
// 				}
// 			}
// 		}
// 		//cout<<maxi<<endl;
// 		vector<lli > v;
// 		lli last=Arr[z];
// 		Arr[z]=0;
		
// 		lli k=z;
// 		for(lli i=z-1; i>=0 ;i--)
// 		{
// 			if(Arr[i]<last && lis[i]+1==lis[k])
// 			{
// 				last=Arr[i];
// 				Arr[i]=0;
// 				k=i;
// 			}
// 		}

// 		for(lli i=N-1;i>=0;i--)
// 		{
// 			if(Arr[i]!=0)
// 			{
// 				v.push_back(Arr[i]);
// 			}
// 		}
// 		for(lli i=0;i<v.size();i++)
// 		{
// 			cout<<v[i]<<" ";
// 		}
// 		cout<<endl;
// 		for(lli i=0;i<N;i++)
// 		{
// 			lis[i]=1;
// 		}
// 		z=0;
// 		maxi=1;
// 		for(lli i=1;i<v.size();i++)
// 		{
// 			for(lli j=0;j<i;j++)
// 			{
// 				if(v[j]<v[i])
// 				{
// 					if(lis[i]<lis[j]+1)
// 					{
// 						lis[i]=lis[j]+1;
// 						if(lis[i]>maxi)
// 						{
// 							maxi=lis[i];
// 							z=i;
// 						}	
// 					}
// 				}
// 			}
// 		}
// 		//cout<<maxi<<endl;
// 		vector<lli> v1;
// 		last=v[z];
// 		v[z]=0;
// 	//	cout<<last<<endl;
// 		k=z;
// 		for(lli i=z-1; i>=0 ;i--)
// 		{
// 			//cout<<last<<" "<<v[i]<<" "<<lis[i]<<" "<<lis[k]<<endl;
// 			if(v[i]<last && lis[i]+1==lis[k])
// 			{
// 				last=v[i];
// 				v[i]=0;
// 				k=i;
// 			}
// 		}

// 		for(lli i=v.size()-1;i>=0;i--)
// 		{
// 			//cout<<v[i]<<" ";
// 			if(v[i]!=0)
// 			{
// 				v1.push_back(v[i]);
// 			}
// 		}

// 		for(lli i=0;i<v1.size();i++)
// 		{
// 			cout<<v1[i]<<" ";
// 		}
// 		cout<<endl;
// 		//cout<<endl;
// 		cout<<v1.size()<<endl;

// 	}
		
// }

#include<iostream>
#include<bits/stdc++.h>
# define INF 11111111
using namespace std;
typedef long long int lli;
lli dp[222][222][222];
lli a[222];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli N;
		cin>>N;
		if(N==-1)
		{
			return 0;
		}
		//lli a[N+1];
		for(lli i=1;i<=N;i++)
		{
			cin>>a[i];
		}

	//	memset(dp,0,sizeof(dp));
		lli val1, val2, val3;
		for (lli i=N+1; i>=1; i--)
        {
            for (lli prevw=0; prevw<=N; prevw++)
            {
                for (lli prevb=0; prevb<=N; prevb++)
                {
                    if(i==N+1)
                    {
                        dp[i][prevw][prevb]=0;
                        continue;
                    }
                    val1=INF;
                    val2=INF;
                    val3=INF;
                    if(prevb==0)
                    {
                        val1=dp[i+1][prevw][i];
                    }
                    if(prevw==0)
                    {
                        val2=dp[i+1][i][prevb];
                    }
                    if(a[i]>a[prevb] && prevb!=0)
                    {
                        val1=dp[i+1][prevw][i];
                    }
                    if(a[i]<a[prevw] && prevw!=0)
                    {
                        val2=dp[i+1][i][prevb];
                    }
                    val3=1+dp[i+1][prevw][prevb];
                    dp[i][prevw][prevb]=min(val1,min(val2,val3));
                }
            }
		}

		cout<<dp[1][0][0]<<endl;
	}
}