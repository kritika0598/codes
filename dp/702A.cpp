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
	lli LIS[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		LIS[i]=1;
	}
	lli maxi=1;
	for(lli i=1;i<N;i++)
	{
		//for(lli j=0;j<i;j++)
		{
			if(Arr[i]>Arr[i-1] && LIS[i]<LIS[i-1]+1)
			{
				LIS[i]=LIS[i-1]+1;
				if(maxi<LIS[i])
				{
					maxi=LIS[i];
				}
			}
		}
	}

	cout<<maxi<<endl;
}