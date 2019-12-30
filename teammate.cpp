#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
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
		lli arr[N+1];
		lli occ[1000006];
		memset(occ,0,sizeof(occ));
		for(lli i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+N);
		lli p,q,r;
		for(lli i=0;i<N;i++)
		{
			occ[arr[i]]++;
		}
		lli cnt=1;
		lli x;
		lli b;
		lli z1=1;
		lli z2=1;
		for(lli i=N-1;i>=0;i=i-2)
		{
			//b=i-1;
			z1=occ[arr[i]];
			occ[arr[i]]--;
			z2=occ[arr[i-1]];
			occ[arr[i-1]]--;
			if(arr[i]==arr[i-1])
				z1=z1/2;
			cnt=(cnt*z1*z2)%mod;
		}
		cout<<cnt<<endl;
	}
		
}