#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool prime[32005];
	lli p[32005];
	memset(prime,false,sizeof(prime));
	for(lli i=2;i<=32000;i++)
	{
		if(!prime[i])
		{
			for(lli j=i+i;j<=32000;j=j+i)
			{
				prime[j]=true;
			}
		}
	}
	lli k=0;
	for(lli i=2;i<=32000;i++)
	{
		if(!prime[i])
		{
			p[k]=i;
			k++;
		}
	}

	// for(lli i=0;i<k;i++)
	// {
	// 	cout<<p[i]<<" ";
	// }
	// cout<<endl;
	lli T;
	cin>>T;
	while(T--)
	{
		lli m,n;
		cin>>m>>n;
		if(m<=1)
			m=2;
		if(m%2!=0)
		{
			lli temp;
			for(lli i=m;i<=n;i=i+2)
			{
				temp=0;
				for(lli j=0;j<k;j++)
				{
					if(p[j]>i)
						break;
					if(p[j]!=i && i%p[j]==0)
					{
						temp++;
						break;
					}
					if(p[j]==i)
					{
						break;
					}
				}
				if(temp==0)
				{
					cout<<i<<endl;
				}
			}
		}
		else
		{
			lli temp=0;
			lli mini=min(k,m+1);
			for(lli i=0;i<mini;i++)
			{
				if(p[i]!=m && m%p[i]==0)
				{
					temp++;
					break;
				}
				if(p[i]==m)
				{
					break;
				}
			}
			if(temp==0)
			{
				cout<<m<<endl;
			}
			for(lli i=m+1;i<=n;i=i+2)
			{
				temp=0;

				for(lli j=0;j<k;j++)
				{
					if(p[j]>i)
						break;
					if(p[j]!=i && i%p[j]==0)
					{
						temp++;
						break;
					}
					if(p[j]==i)
					{
						break;
					}
				}
				if(temp==0)
				{
					cout<<i<<endl;
				}
			}
		}
		cout<<endl;
		
	}
}