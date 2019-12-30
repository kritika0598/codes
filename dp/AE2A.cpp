#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli DP[1000][6000];

lli foo(lli n, lli k)
{
	if(DP[n][k]!=-1)
		return DP[n][k];
	if(k<n || k>6*n)
		return 0;
	if(n==1 && k<=6)
		return DP[n][k]=100/6;
	return DP[n][k]=(foo(n-1,k-1)+foo(n-1,k-2)+foo(n-1,k-3)+foo(n-1,k-4)+foo(n-1,k-5)+foo(n-1,k-6))/6.0;

}





int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	for(lli i=0;i<1000;i++)
	{
		for(lli j=0;j<6000;j++)
		{
			DP[i][j]=-1;
		}
	}
	while(T--)
	{
		lli n,k;
		cin>>n>>k;
		memset(DP,-1,sizeof(DP));
		double m=n;
		if(n>570)
			cout<<0<<endl;
		else if(n<571 && k>=570*6)
			cout<<0<<endl;
		else
		{
			// double c=0.166666666666667;
			// double b=pow(c,m);
		//	cout<<m<<" "<<b<<endl;
		//	cout<<foo(n,k)<<endl;
			cout<<floor(foo(n,k))<<endl;
		}	
			
	}
}