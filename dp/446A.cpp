#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli maxi=0;
lli solve(lli i, lli N, lli prev,lli k)
{
	if(i>=N)
		return 0;
	if(i==N-1 && Arr[i]>prev)
		return 1;
	if(i==N-1 && k==0)
		return 0;
	if(i==N-1 && k==1)
		return 1;
	if(i==0)
	{
		lli a;
		if(k!=0)
			a=max(1+solve(i+1,N,Arr[i],1),1+solve(i+1,N,Arr[i+1]-1,0));
		else
			a=1+solve(i+1,N,Arr[i],0);
		maxi=max(maxi,a);
		return a;
	}
	if(Arr[i]>prev)
	{
		lli a;
		if(k==0)
			a=1+solve(i+1,N,Arr[i],0);
		else
		{
			a=max(1+solve(i+1,N,Arr[i],1),1+solve(i+1,N,Arr[i+1]-1,0));
		}
		maxi=max(maxi,a);
		return a;
	}
	else
	{
		lli a;
		if(k==0)
		{
			a=solve
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N];
	lli temp[N];
	lli LIS1[N];
	lli LIS2[N];
	bool f[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		if(i>=1)
		{
			temp[i]=Arr[i-1]+1;
		}
		
		LIS1[i]=1;
		LIS2[i]=1;
		f[i]=false;
	}

	for(lli i=1;i<N;i++)
	{
		for(lli j=0;j<i;j++)
		{
			if(Arr[i]>Arr[j] && (LIS1[i]<LIS1[j]+1))
			{
				LIS1[i]=LIS1[j]+1;
			}
			if(Arr[i]>Arr[j] && (LIS2[i]<LIS2[j]+1))
			{
				LIS2[i]=LIS2[j]+1;
				f[i]=true;
			}
		}
		if(Arr[i]<Arr[i-1])
		{
			if()
		}
	}
}