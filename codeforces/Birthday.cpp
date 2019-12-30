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
	lli Arr[N+1];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	sort(Arr,Arr+N);

	lli G[N];
	lli j=0;
	bool flag=true;
	for(lli i=0;i<N;i++)
	{
		if(flag)
		{
			G[i]=Arr[j];
			j=j+2;
			if(j>=N)
			{
				flag=false;
				if(j-2==N-2)
				{
					j=N-1;
				}
				else
				{
					j=N-2;
				}
				
			}
		}
		else
		{
			G[i]=Arr[j];
			j=j-2;
		}
		
	}

	for(lli i=0;i<N;i++)
	{
		cout<<G[i]<<" ";
	}
	cout<<endl;		
}