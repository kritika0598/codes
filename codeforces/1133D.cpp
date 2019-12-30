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
	long double A[N+1];
	long double B[N+1];

	for(lli i=0;i<N;i++)
	{
		cin>>A[i];
	}

	for(lli i=0;i<N;i++)
	{
		cin>>B[i];
	}

	map<long double,lli> m;
	lli maxi=0;
	lli ans=0;
	for(lli i=0;i<N;i++)
	{
		if(A[i]==0 && B[i]==0)
		{
			ans++;
		}
		if(A[i]!=0)
		{
			//cout<<(-B[i])/A[i]<<endl;
			m[(-B[i])/A[i]]++;
			if(m[(-B[i])/A[i]]>maxi)
			{
				maxi=m[(-B[i])/A[i]];
			}
		}
		
	}

	cout<<maxi+ans<<endl;



}