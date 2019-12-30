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
	lli N;
	while(T--)
	{
		cin>>N;
		lli A[N+1];
		lli B[N+1];
		bool flag=false;
		bool f=false;
		for(lli i=0;i<N;i++)
		{
			cin>>A[i];
		}
		for(lli i=0;i<N;i++)
		{
			cin>>B[i];
			if(A[i]>B[i])
				flag=true;
		}
		lli x=0;
		if(flag)
		{
			cout<<"NIE"<<endl;
			//continue;
		}
		else
		{
			for(lli i=0;i<N;i++)
			{
				B[i]=B[i]-A[i];
				A[i]=0;
			}
			for(lli i=0;i<N-2;i++)
			{
				if(A[i]<=B[i])
				{
					x=B[i]-A[i];
					A[i]=A[i]+x;
					A[i+1]=A[i+1]+2*x;
					A[i+2]=A[i+2]+3*x;
				}
				else
				{
					f=true;
					//cout<<"NIE"<<endl;
					//break;
				}
				
			}
			if(A[N-2]!=B[N-2])
			{
				f=true;
			}
			if(A[N-1]!=B[N-1])
			{
				f=true;
			}
			if(f)
			{
				cout<<"NIE"<<endl;
			}
			else
			{
				cout<<"TAK"<<endl;
			}
			
		}
	}
		
}