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
		lli N,K;
		cin>>N>>K;
		lli Arr[N];
		lli sum=0;
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
			sum=sum+Arr[i];
		}
		sort(Arr,Arr+N);
		// if(sum-Arr[0]>K || Arr[N-1]-sum>K)
		// {
		// 	cout<<-1<<endl;
		// 	continue;
		// }
		// else
		{
			lli p=Arr[0]+K;
			if(Arr[N-1]-p<=K)
			{
				cout<<p<<endl;
				continue;
			}
			else
			{
				cout<<-1<<endl;
				continue;
			}
		}

	}	
}