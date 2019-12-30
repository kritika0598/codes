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

	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	sort(Arr,Arr+N);
	lli ans=0;
	for(lli i=0;i<N/2;i++)
	{
		ans=ans+pow((Arr[i]+Arr[N-i-1]),2);
	}

	cout<<ans<<endl;
}