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
		lli arr[N+1];
		lli b[N+1];
		lli asum=0,bsum=0;
		lli cnt=0;
		for(lli i=0;i<N;i++)
		{
			cin>>arr[i];
			if(arr[i]==1)
				cnt++;
			b[i]=arr[i]*arr[i];
			asum=asum+arr[i];
			bsum=bsum+b[i];
		}
		sort(arr,arr+N);
		sort(b,b+N);
		lli dif=bsum-asum;
		lli x;
		if(K>=(N-cnt))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
		
}