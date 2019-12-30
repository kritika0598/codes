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
	lli sum=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		sum=sum+Arr[i];
	}
	lli prevSum=sum;
	sort(Arr,Arr+N);
	lli j=N-1;
	while(j!=0)
	{
		//cout<<i<<" "<<maxPrimeFactors(Arr[i])<<endl;
		for(lli i=2;i<Arr[j];i++)
		{
			if(Arr[j]%i==0)
			{
				if(prevSum>(sum-Arr[j]-Arr[0]+Arr[0]*i+Arr[j]/i))
					prevSum=sum-Arr[j]-Arr[0]+Arr[0]*i+Arr[j]/i;
			}
		}
		j--;
	}

	cout<<prevSum<<endl;
	
}