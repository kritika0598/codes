#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	lli Arr[N];
	lli ans=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	for(lli i=0;i<N-1;i++)
	{
		if(Arr[i]+Arr[i+1]<K)
		{
			ans+=(K-abs(Arr[i+1]+Arr[i]));
			Arr[i+1]+=(K-abs(Arr[i+1]+Arr[i]));			
		}
	}

	cout<<ans<<endl;
	for(lli i=0;i<N;i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}