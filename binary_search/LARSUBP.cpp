#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	//while(T--)
	for(lli k=1;k<=T;k++)
	{
		string S;
		cin>>S;
		int N;
		N=S.size();
	//	cout<<N<<endl;
		lli Dp[N];
		lli Dp1[11];
		for(int i=0;i<=9;i++)
		{
			Dp1[i]=0;
		}
		//int Arr[N];
		lli ans=0;
		for(int i=0;i<N;i++)
		{
			lli j=S[i]-'0';
			//Dp1[j]++;
			for(int a=0;a<j;a++)
			{
				Dp1[j]=(Dp1[j]+Dp1[a])%MOD;
			}
			Dp1[j]++;
		}
		for(int i=0;i<=9;i++)
		{
			ans=(ans+Dp1[i])%MOD;
			//cout<<ans<<" ";
		}
		//cout<<endl;

		cout<<"Case "<<k<<": "<<ans<<endl;
	}
		
}