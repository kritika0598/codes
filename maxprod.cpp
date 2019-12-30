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
		double N,K;
		cin>>N>>K;
		if(K>N)
		{
			cout<<"-1"<<endl;
			continue;
		}
		if(K>N/2)
		{
			cout<<0<<endl;
				continue;
		}
		else
		{
			double x=floor(N/K);
			double b=N/K;
			cout<<b<<endl;
			b=b-x;
			cout<<b<<endl;
			lli z=b*K;
			cout<<z<<endl;
			lli a=K-z;
			cout<<a<<endl;
			lli p=pow(((x*x)-x),a);
			x=x+1;
			lli k=pow(((x*x)-x),z);
			p=p*k;
			cout<<p<<endl;
		}
	}
		
}