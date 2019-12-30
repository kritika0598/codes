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
		lli brr[K+1];
		memset(brr,0,sizeof(brr));
		lli crr[N+1];
		for(lli i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+N);
		lli min=INT_MAX;
		lli l=0;
		lli a=0;
		lli x=(M+1)*L;
		crr[0]=x;
		for(lli i=0;i<N;i++)
		{
			crr[i]=x+(i)*L-arr[i];
			if(crr[i]<=min && arr[i]<=K)
			{
				//l=arr[i];
				min=crr[i];
				//a=i;
			}

		}
		lli b=0;
		lli c=1;

		if(K>arr[N-1])
		{
			l=(M+N+1)*L-K;
			if(l<min)
				min=l;
		}
		/*for(lli i=0;i<N;i++)
		{
			cout<<arr[i]<<endl;
		}*/

		/*for(lli i=1;i<=K;i++)
		{
			if(i<=arr[b])
			{
				brr[i]=x+((b)*L)-i;
				if(brr[i]<min)
				{
					min=brr[i];
					c=i;
				}
				//cout<<"hello"<<endl;	
			}
			else
			{
				b++;
				if(b>=N)
				{
					break;
				}
				i--;
			}

			//cout<<i<<" "<<arr[b]<<" "<<brr[i]<<endl;
		}*/
	//	brr[arr[N-1]+1]=(M+N+1)*x-arr[N-1]-1;
		//if(brr[arr[N-1]+1]<min)
			//min=brr[arr[N-1]]
		/*if(K>arr[N-1])
			brr[K]=(M+N+1)*L-K;
		if(brr[K]<min)
			min=brr[K];*/
		//cout<<((M+N+1)*x)<<endl;
		//cout<<brr[K]<<endl;
		/*for(lli i=1;i<=K;i++)
		{
			cout<<brr[i]<<" ";
		}
		cout<<endl;*/

		if(min<0)
			min=0;
		cout<<min<<endl;
	}
		
}