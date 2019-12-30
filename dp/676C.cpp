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
	char s[N+1];
	//cin>>s;
	for(lli i=1;i<=N;i++)
	{
		cin>>s[i];
	}
	lli A[N+1];
	lli B[N+1];
	A[0]=0;
	B[0]=0;
	for(lli i=1;i<=N;i++)
	{
		{
			if(s[i]=='a')
			{
				A[i]=A[i-1]+1;
				B[i]=B[i-1];
			}
			else
			{
				B[i]=B[i-1]+1;
				A[i]=A[i-1];
			}
		}
	}

	lli l=0;
	lli h=N;
	lli ans=0;
	while(l<=h)
	{
		lli mid=(h+l)/2;
		bool f=false;
		for(lli i=mid;!f & i<=N;i++)
		{
			if(A[i]-A[i-mid]<=K)
				f=true;
			if(B[i]-B[i-mid]<=K)
				f=true;
		}
		if(f)
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			h=mid-1;
		}
	}
	cout<<ans<<endl;
}