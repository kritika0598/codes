#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
//lli *Arr1=new lli[1000000005];
lli Arr1[1000005];
map<lli,lli>m;
lli x(lli n)
{
	if(m[n]!=0)
		return m[n];
	//cout<<"hello"<<endl;
	if(n<=1000000)
	{
		//cout<<Arr1[n]<<endl;
		return Arr1[n];
	}
	m[n]= max((x(n/2)+x(n/3)+x(n/4)),n);
	return m[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t=10;
	Arr1[0]=0;

	for(lli i=1;i<=1000000;i++)
	{
		if((Arr1[i/2]+Arr1[i/3]+Arr1[i/4])<=i)
			Arr1[i]=i;
		else
			Arr1[i]=Arr1[i/2]+Arr1[i/3]+Arr1[i/4];
	}

	while(t--)
	{
		lli N;
		cin>>N;
		if(N<=1000000)
			cout<<Arr1[N]<<endl;
		else
		{
			lli result=x(N);
			cout<<result<<endl;
		}
		//cout<<Arr1[N]<<endl;

	}
		
}