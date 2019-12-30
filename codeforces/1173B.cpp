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
	if(N==1)
	{
		cout<<1<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	else if(N==2)
	{
		cout<<2<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0;
	}
	//else if(N%2==0)
	{
		lli a=(N+2)/2;
		cout<<a<<endl;
		lli j=1;
		lli k=2;
		for(lli i=1;i<=N;i++)
		{
			if(j<=a)
			{
				cout<<1<<" "<<j<<endl;
				j++;
			}
			else
			{
				cout<<k<<" "<<a<<endl;
				k++;
			}
		}
	}
	return 0;
}