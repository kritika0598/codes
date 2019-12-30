#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


lli Pmk[200];

int sieveOfEratosthenes(int s, int e)

{

	bool prime[e+1];
	memset(prime, true, sizeof(prime));
	if(s<=2)
	{
		for(int p=2; p*p<=e ;p++)
		{
			if(prime[p]==true)
			{
				for(int i=2*p;i<=e;i=i+p)
					prime[i]=false;

			}
		}
	}
	lli k=0;
	for(int i=s;i<=e;i++)
	{
		if(prime[i])
		{
			Pmk[k++]=i;
			//cout<<i<<" ";
		}	
	}
	//cout<<endl;
	return k;
}




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	lli k= sieveOfEratosthenes(2, 200);

	lli mk[50000];
	lli x=0;
	for(lli i=0;i<k-1;i++)
	{
		for(lli j=i+1;j<k;j++)
		{
			mk[x++]=Pmk[i]*Pmk[j];
			//cout<<mk[x-1]<<" ";
		}
	}
	//cout<<endl;
	sort(mk,mk+x);
	cin>>T;
	while(T--)
	{
		lli n;
		cin>>n;
		bool flag=false;
		lli j=0;
		for(lli i=0;i<x;i++)
		{
			if(mk[i]>=n)
			{
				j=i;
				break;
			}
		}
		for(lli i=0;i<j-1;i++)
		{
			for(lli m=i;m<j;m++)
			{
				if(mk[i]+mk[m]==n)
				{
					flag=true;
					//cout<<mk[i]<<" "<<mk[m]<<endl;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
		
}