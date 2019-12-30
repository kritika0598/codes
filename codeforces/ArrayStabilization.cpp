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
	lli mini=100005, mini2=100005, maxi=0, maxi2=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		// if(Arr[i]<=mini)
		// {
		// 	mini2=mini;
		// 	mini=Arr[i];
		// }
		// else if(Arr[i]>=maxi)
		// {
		// 	maxi2=maxi;
		// 	maxi=Arr[i];
		// }	
	}
	sort(Arr,Arr+N);


	if(Arr[N-1]-Arr[1]>Arr[N-2]-Arr[0])
	{
		cout<<Arr[N-2]-Arr[0]<<endl;
	}
	else
	{
		cout<<Arr[N-1]-Arr[1]<<endl;
	}		
}