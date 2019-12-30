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
	lli Arr[N];
	lli K;
	cin>>K;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	lli count=0;
	for(lli i=0;i<N;i++)
	{
		lli val=Arr[i]-K;
		lli l=0;
		lli h=N-1;
		bool flag=false;
		while(l<h)
		{
			lli mid=l+(h-l+1)/2;
			if(Arr[mid]>val)
				h=mid-1;
			else if(Arr[mid]<val)
				l=mid+1;
			else
			{
				count++;
				flag=true;
				break;
			}
		}
		if(!flag && l==h && Arr[l]==val)
		{
			count++;
		}
	}
	cout<<count<<endl;
}