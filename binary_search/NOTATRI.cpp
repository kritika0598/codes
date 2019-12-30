#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli N;
		cin>>N;
		if(N<3)
			return 0;
		lli Arr[N+1];
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}
		sort(Arr,Arr+N);

		lli count=0;

		for(lli i=0;i<N;i++)
		{
			for(lli j=i+1;j<N-1;j++)
			{
				lli val=Arr[i]+Arr[j];
				lli x=upper_bound(Arr,Arr+N,val)-Arr;
				count=count+(N-x);	
			}
		}
		cout<<count<<endl;

	}
	

}