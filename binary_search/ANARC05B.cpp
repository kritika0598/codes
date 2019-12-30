#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Arr1[1000005];
lli Arr2[1000005];
lli Sum1[1000005];
lli Sum2[1000005];
lli ind1[1000005];
lli ind2[1000005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(1)
	{
		lli N;
		cin>>N;
		if(N==0)
			break;
		memset(Arr1,0,sizeof(Arr1));
		memset(Arr2,0,sizeof(Arr2));
		memset(Sum1,0,sizeof(Sum1));
		cin>>Arr1[0];
		Sum1[0]=Arr1[0];
		for(lli i=1;i<N;i++)
		{
			cin>>Arr1[i];
			Sum1[i]=Sum1[i-1]+Arr1[i];
		}
		lli M;
		cin>>M;

		memset(Sum2,0,sizeof(Sum2));
		cin>>Arr2[0];
		Sum2[0]=Arr2[0];

		memset(ind2,0,sizeof(ind2));
		memset(ind1,0,sizeof(ind1));

		lli k=0;
		lli count=0;
		for(lli i=1;i<M;i++)
		{
			cin>>Arr2[i];
			Sum2[i]=Sum2[i-1]+Arr2[i];
		}
		for(lli i=0;i<M;i++)
		{
			lli l=0;
			lli h=N-1;
			while(l<h)
			{
				lli mid=l+(h-l+1)/2;
				if(Arr1[mid]>Arr2[i])
					h=mid-1;
				else if(Arr1[mid]<Arr2[i])
					l=mid+1;

				else
				{
					ind1[k]=mid;
					ind2[k]=i;
					k++;
					//cout<<Arr1[mid]<<endl;
					break;
				}
			}
			if(l==h && Arr1[l]==Arr2[i])
			{
				ind1[k]=l;
				ind2[k]=i;
				k++;
				//cout<<Arr1[l]<<endl;
			}
		}

		// for(lli i=0;i<k;i++)
		// {
		// 	cout<<ind1[i]<<" ";
		// }
		// cout<<endl;
		// for(lli i=0;i<k;i++)
		// {
		// 	cout<<ind2[i]<<" ";
		// }
		// cout<<endl;



		// for(lli i=0;i<N;i++)
		// {
		// 	cout<<Sum1[i]<<" ";
		// }
		// cout<<endl;
		// for(lli i=0;i<M;i++)
		// {
		// 	cout<<Sum2[i]<<" ";
		// }
		// cout<<endl;
		lli ans=0;
		if(k!=0)
		{
			ans=max(Sum1[ind1[0]],Sum2[ind2[0]]);
			//cout<<ans<<endl;
			for(lli i=1;i<k;i++)
			{
				ans=ans+max(Sum1[ind1[i]]-Sum1[ind1[i-1]], Sum2[ind2[i]]-Sum2[ind2[i-1]]);
				//cout<<ans<<endl;
			}
			//cout<<(Sum1[N-1]-Sum1[ind1[k-1]])<< " "<<Sum2[M-1]-Sum2[ind2[k-1]]<<endl;
			ans=ans+max(Sum1[N-1]-Sum1[ind1[k-1]], Sum2[M-1]-Sum2[ind2[k-1]]);
		}
		else
		{
			ans=max(Sum1[N-1],Sum2[M-1]);
		}
		



		cout<<ans<<endl;
		continue;
	}
		
}