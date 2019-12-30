#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli Arr[100];
	Arr[0]=1;
	for(lli i=1;i<40;i++)
	{
		if(i%2!=0)
			Arr[i]=0;
	}
	Arr[2]=8;
	for(lli i=4;i<18;i=i+2)
	{
		Arr[i]=Arr[2]*Arr[i-2];
		for(lli j=2;j<=i-4;j=j+2)
		{
			Arr[i]+=31*Arr[j];
		}
		Arr[i]=Arr[i]+31;
	}
	while(1)
	{
		lli N;
		cin>>N;
		if(N==-1)
			return 0;

		cout<<Arr[N]<<endl;		
	}

}