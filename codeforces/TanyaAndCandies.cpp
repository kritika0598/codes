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
	lli Arr[N+1];
	lli odd[N+1];
	lli even[N+1];
	odd[0]=0;
	even[0]=0;
	lli k=1,l=1;
	lli esum=0;
	lli essum[N+1];
	lli osum=0;
	lli ossum[N+1];
	essum[0]=0;
	ossum[0]=0;
	lli p[N+1];
	for(lli i=1;i<=N;i++ )
	{
		cin>>Arr[i];
		if(i%2==0)
		{
			even[k]=i;
			essum[k]=essum[k-1]+Arr[i];
			k++;
			esum+=Arr[i];
			p[i]=k-1;
		}
		else
		{
			odd[l]=i;
			ossum[l]=ossum[l-1]+Arr[i];
			l++;
			osum+=Arr[i];
			p[i]=l-1;
		}	
	}
	lli count=0;
	if(osum-Arr[1]==esum)
		count++;
	if(N%2==0)
	{
		if(esum-Arr[N]==osum)
			count++;
	}
	else
	{
		if(osum-Arr[N]==esum)
			count++;
	}
	//cout<<count<<endl;
	for(lli i=2;i<=N-1;i++)
	{
		if(i%2==0)
		{
			//cout<<p[i]<<" "<<esum<<" "<<Arr[i]<<" "<<ossum[p[i]]<<" "<<essum[p[i]-1]<<" "<<osum<<" "<<ossum[p[i]]<<" "<<essum[p[i]-1]<<endl;
			//cout<<esum-Arr[i]+ossum[p[i]]-essum[p[i]-1]<<" "<<osum-ossum[p[i]]+essum[p[i]-1]<<endl;
			if(esum-Arr[i]+ossum[p[i]]-essum[p[i]-1]==osum-ossum[p[i]]+essum[p[i]-1])
				count++;
		}
		else
		{
			//cout<<esum-essum[p[i]-1]+ossum[p[i]-1]<<" "<<osum-Arr[i]+essum[p[i]-1]-ossum[p[i]-1]<<endl;
			if(esum-essum[p[i]-1]+ossum[p[i]-1]==osum-Arr[i]+essum[p[i]-1]-ossum[p[i]-1])
				count++;
		}
		
	}

	cout<<count<<endl;


}