#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	lli Arr[1000005];

	lli N,M;
	cin>>N>>M;
	memset(Arr,0,sizeof(Arr));	
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	sort(Arr,Arr+N);
	for(lli i=1;i<N;i++)
	{
		Arr[i]=Arr[i-1]+Arr[i];
	}
	// for(lli i=0;i<N;i++)
	// {
	// 	cout<<Arr[i]<<" ";
	// }
	// cout<<endl;
	lli sum=Arr[N-1];
	for(lli i=N-1;i>0;i--)
	{
		Arr[i]=sum-(N-i)*(Arr[i]-Arr[i-1])-Arr[i-1];   //amount of wood that he will get if he cuts at Arr[i height]
		
	}
	Arr[0]=sum-(N)*(Arr[0]);

	// for(lli i=0;i<N;i++)
	// {
	// 	cout<<Arr[i]<<" ";
	// }
	// cout<<endl;
	lli l=0;
	lli h=N-1;
	while(l<h)
	{
		lli mid=l+(h-l+1)/2;
		if(Arr[mid]>=M)
			l=mid;
		else
			h=mid-1;

	}
	lli x=Arr[l]-M;
	lli y=M-Arr[l+1];

//	cout<<x<<endl;
	Arr[0]=(sum-Arr[0])/N;
	for(lli i=1;i<N;i++)
	{
		Arr[i]=(sum-Arr[i-1]-Arr[i])/(N-i)+Arr[i-1];
		
	}
	for(lli i=N-1;i>=1;i--)
	{
		Arr[i]=Arr[i]-Arr[i-1];
	}
	// for(lli i=0;i<N;i++)
	// {
	// 	cout<<Arr[i]<<" ";
	// }
	// cout<<endl;
	bool flag1=true;
	if(x==0)
		cout<<Arr[l]<<endl;
	else if(x<0)
	{
		x=-1*x;

		if(x%N==0)
			x=x/N;
		else
			x=(x/N)+1;
		cout<<Arr[0]-x<<endl;
	}	
	else
	{
		if((x/(N-l-1))<=0)
		{
			x=0;
		}	
		else if(y%(N-l-1)==0)
		{
			y=y/(N-l-1);
			flag1=false;
			//x=-y;
		}	
		else
		{
			y=y/(N-l-1)+1;
			flag1=false;
			//x=-y;
		}
		if(flag1)
			cout<<Arr[l]+x<<endl;
		else
			cout<<Arr[l+1]-y<<endl;

	}
}