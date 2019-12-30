#include<iostream>
#include<bits/stdc++.h>

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
		lli N,M,K,L;
		cin>>N>>M>>K>>L;
		lli arr[N+1];
		for(lli i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+N);
		lli min=INT_MAX;
		lli l;
		lli x=(M+1)*L;
		for(lli i=0;i<N;i++)
		{
			l=x+(i)*L-arr[i];
			if(l<=min && arr[i]<=K)
			{
				//l=arr[i];
				min=l;
				//a=i;
			}
			if(arr[i]>K)
				break;

		}

		if(K>arr[N-1])
		{
			l=(M+N+1)*L-K;
			if(l<min)
				min=l;
		}
		if(min<0)
			min=0;
		cout<<min<<endl;
	}
		
}