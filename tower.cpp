#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;
	lli arr[n+5];
	lli h[200005];
	memset(h,0,200005);
	lli max=0;
	lli e=1;
	for(lli i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
			max=arr[i];
		for(lli i=1;i<=arr[i];i++)
		{
			h[i]++;
			if((h[i]==n) && i>e)
				e=i;
		}
	}
	lli cnt=1;
	lli p=0;
	for(lli i=max;i>=e;i--)
	{
		p=p+h[i];
		if(p>=k)
		{
			cnt++;
			p=0;
			//i++;
		}
	}
	if(e==max)
		cout<<0<<endl;
	else
		cout<<cnt<<endl;
		
}
