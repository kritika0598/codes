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
	lli arr[55];
	memset(arr,0,sizeof(arr));
	arr[1]=1;
	arr[2]=2;
	arr[3]=4;
	for(lli i=4;i<=50;i++)
	{
		arr[i]=arr[i]+arr[i-1]+arr[i-2]+arr[i-3];
	}
	while(T--)
	{
		lli N;
		cin>>N;
		cout<<arr[N]<<endl;

	}
		
}