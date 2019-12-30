#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,K;
		cin>>N>>K;
		lli arr[K+1];
		lli a;
		a=N/K;
		lli x=(K/2);
		lli sum=0;
		bool flag =false;
		if(K>N)
		{
			cout<<"-1"<<endl;
			continue;
		}

		if(K%2!=0)
		{
			x++;
			lli b=1;
			arr[x]=a;
			sum=a;
			for(lli i=x+1,j=x-1;i<=K,j>=1;i++,j--)
			{
				arr[i]=a+b;
				arr[j]=a-b;
				b++;
				if(arr[j]<=0)
				{
					//cout<<"-1"<<endl;
					flag=true;
					break;
					//continue;
				}
				sum=sum+arr[i]+arr[j];
			}

		}
		else
		{
			lli b=1;
			for(lli i=x+1,j=x;i<=K,j>=1;i++,j--)
			{
				arr[i]=a+b;
				arr[j]=a-b;
				b++;
				if(arr[j]<=0)
				{
					//cout<<"-1"<<endl;
					flag=true;
					break;
					//continue;
				}
				sum=sum+arr[i]+arr[j];
			}
		}
		if(flag)
		{
			cout<<"-1"<<endl;
			continue;
		}
	/*	for(lli i=1;i<=K;i++)
		{
			cout<<arr[i]<<" ";
		}	*/
		//cout<<endl;
		if(sum<N)
		{
			x=N-sum;
			if(K%2!=0)
			{
				for(lli i=K;i>0;i--)
				{
					arr[i]++;
					x--;
					if(x==0)
						break;
				}
			}
			else
			{
				for(lli i=K/2;i>0;i--)
				{
					arr[i]++;
					x--;
					if(x==0)
						break;
				}
				if(x!=0)
				{
					for(lli i=K;i>0;i--)
					{
						arr[i]++;
						x--;
						if(x==0)
							break;
					}
				}
			}
		}


		/*for(lli i=1;i<=K;i++)
		{
			cout<<arr[i]<<" ";
		}	
		cout<<endl;*/
		x=1;
		for(lli i=1;i<=K;i++)
		{
			x=(x*((arr[i]*arr[i])%mod-arr[i]%mod)%mod)%mod;
		}
		cout<<x<<endl;



	}
}