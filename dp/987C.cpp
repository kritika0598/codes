#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	lli cost[N];
	for(lli i=0;i<N;i++)
	{
		cin>>cost[i];
	}
	lli temp[N];
	lli temp2[N];
	for(lli i=0;i<N;i++)
	{
		temp[i]=1000000000007;
		temp2[i]=1000000000007;

	}
	for(lli i=1;i<N;i++)
	{
		for(lli j=0;j<i;j++)
		{
			if(Arr[i]>Arr[j] && temp[i]>cost[j]+cost[i])
			{
				temp[i]=cost[j]+cost[i];
			}
		}
	}
	lli mini=1000000000007;
	for(lli i=2;i<N;i++)
	{
		for(lli j=1;j<i;j++)
		{
			if(Arr[i]>Arr[j] && temp2[i]>temp[j]+cost[i])
			{
				temp2[i]=temp[j]+cost[i];
				if(temp2[i]<mini)
					mini=temp2[i];
			}
		}
	}
	if(mini==1000000000007)
		cout<<-1<<endl;
	else
		cout<<mini<<endl;	
}