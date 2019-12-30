#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	lli A[N+1][M+1];
	lli B[N+1][M+1];

	for(lli i=1;i<=N;i++)
	{
		for(lli j=1;j<=M;j++)
		{
			cin>>A[i][j];
		}
	}
	for(lli i=1;i<=N;i++)
	{
		for(lli j=1;j<=M;j++)
		{
			cin>>B[i][j];
		}
	}
	if(A[1][1]!=B[1][1])
	{
		cout<<"NO"<<endl;
		return 0;
	}	
	else if(A[N][M]!=B[N][M])
	{
		cout<<"NO"<<endl;
		return 0;
	}
	map<lli,lli> m1;
	map<lli,lli> m2;
	for(lli i=1;i<=N;i++)
	{
		lli j=1,k=i;
		m1.clear();
		m2.clear();
		while(j<=M && k>=1)
		{
			m1[A[k][j]]++;
			m2[B[k][j]]++;
			k--;
			j++;
		}
		if(m1!=m2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(lli i=2;i<=M;i++)
	{
		lli j=i,k=N;
		m1.clear();
		m2.clear();
		while(j<=M && k>=1)
		{
			m1[A[k][j]]++;
			m2[B[k][j]]++;
			k--;
			j++;
		}
		if(m1!=m2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	cout<<"YES"<<endl;
}