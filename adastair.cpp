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
		lli N,K;
		cin>>N>>K;
		lli arr[N+1];
		//lli dif[N+1];
		for(lli i=0;i<N;i++)
		{
			cin>>arr[i];
			
		}
		lli cnt=0;
		lli arr1[5000];
		lli p=0;
		lli i=0;
		arr1[0]=arr[0];
		while(1)
		{
			if((arr[i+1]-arr1[p])<=K)
			{
				arr1[p]=arr[i];
				p++;
				i++;
				arr1[p]=arr[i];
			}
			else
			{
				p++;
				//lli dif=(arr[i+1]+arr[i]-K);
				arr1[p]=arr1[p-1]+K;
				cnt++;
			}
			//cout<<arr1[p]<<" ";
			if(i==N-1)
				break;
		}
		cout<<cnt<<endl;
	}
		
}