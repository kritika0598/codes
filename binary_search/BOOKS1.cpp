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
	while(N--)
	{
		lli M,K;
		cin>>M>>K;
		lli Arr[M];
		lli sum=0;
		lli maxi=0;
		lli scrb[K];
		lli scrb1[K];
		memset(scrb1,0,sizeof(scrb1));
		for(lli i=0;i<M;i++)
		{
			cin>>Arr[i];
			sum=sum+Arr[i];
			if(Arr[i]>maxi)
				maxi=Arr[i];
		}
		for(lli i=K-1;i>=0;i--)
		{
			scrb[i]=1;
		}
		scrb[0]=M-K+2;
		//cout<<"hello"<<endl;
		lli low=maxi;
		lli high=sum;
		lli scribers;
		while(low<high)
		{
			lli mid=low+(high-low)/2;
			scribers=1;
			lli pages=0;
			for(lli i=0;i<M;i++)
			{
				if(pages+Arr[i]<=mid)
					pages+=Arr[i];
				else
				{
					scribers++;
					pages=Arr[i];
				}
			}

			if(scribers>K)
				low=mid+1;
			else
				high=mid;
		}
		sum=0;
		// cout<<low<<endl;
		// cout<<scribers<<endl;
		lli k=K-1;
		// for(lli i=0;i<K;i++)
		// {
		// 	cout<<scrb[i]<<" ";
		// }
		// cout<<endl;
		for(lli i=M-1;i>=0;i--)
		{
			//sum=sum+Arr[i];
			if((scrb1[k]+Arr[i]<=low && scrb[0]>1 ) || (scrb1[k]+Arr[i]<=low && (scrb[0]==1 && k==0)))
			{
				scrb[0]--;
				scrb1[k]+=Arr[i];
			}
			else
			{
				k--;
				//sum=Arr[i];
				scrb1[k]+=Arr[i];
				//scrb[0]--;
			}
		}

		// for(lli i=0;i<K;i++)
		// {
		// 	cout<<scrb1[i]<<" ";
		// }
		// cout<<endl;

		sum=0;
		k=0;
		for(lli i=0;i<M;i++)
		{
			sum=sum+Arr[i];
			if(sum==scrb1[k])
			{
				if(i==M-1)
					cout<<Arr[i]<<" ";
				else
					cout<<Arr[i]<<" "<<"/"<<" ";
				k++;
				sum=0;
			}
			else if(sum<scrb1[k])
			{
				cout<<Arr[i]<<" ";
			}	
		}
		cout<<endl;
	}
}