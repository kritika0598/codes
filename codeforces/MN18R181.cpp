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
		lli N;
		cin>>N;

		lli Arr[N];
		lli cum[N];
		lli count=0;
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}

		lli temp[2]={1,0};
		lli result=0,sum=0;

		for(lli i=0;i<=N-1;i++)
		{
			sum=((sum+Arr[i])%2 +2)%2;
			temp[sum]++;
		}

		result+=(temp[0]*(temp[0]-1)/2);
		result+=(temp[1]*(temp[1]-1)/2);

		lli ans=(N*(N+1))/2;
		ans=ans-result;

		cout<<ans<<endl;

	}	
}