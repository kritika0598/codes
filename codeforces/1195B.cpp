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

	lli ans=0;
	// for(lli i=1;i<=N;i++)
	// {
	// 	if(i!=1)
	// 		sum[i]=sum[i-1]+i;
	// 	if((sum[i]-(N-i))==K)
	// 	{
	// 		ans=sum[i];
	// 		break;
	// 	}
	// }

	lli x=sqrt(N+K);
	while(1)
	{
		if((x*x)+(3*x)==2*(N+K))
		{
			break;
		}
		x++;
	}

	cout<<(N-x)<<endl;


}