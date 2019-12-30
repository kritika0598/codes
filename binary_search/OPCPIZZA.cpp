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
		lli N,M;
		cin>>N>>M;
		lli Arr[N];
		lli x;
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}
		sort(Arr,Arr+N);
		lli count=0;
		for(lli i=0;i<N;i++)
		{
			x=M-Arr[i];
			lli up=upper_bound(Arr+i+1,Arr+N,x)-Arr;
			lli low=lower_bound(Arr+i+1,Arr+N,x)-Arr;
			if(up!=low)
				count++;
		}
		cout<<count<<endl;
	}
		
}