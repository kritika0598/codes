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
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	lli ans=Arr[N-1];
	if(ans==1)
	{
		cout<<ans<<endl;
		return 0;
	}
	for(lli i=N-2;i>=0;i--)
	{
		if(Arr[i]>=Arr[i+1])
			Arr[i]=Arr[i+1]-1;
		ans+=Arr[i];
		if(Arr[i]==1)
			break;
	}
	//lli ans=Arr[N-1];
	// for(lli i=N-2;i>=0;i--)
	// {
	// 	if(Arr[i]<Arr[i+1])
	// 		ans=ans+Arr[i];
	// 	else
	// 	{
	// 		if(Arr[i+1]-1<0)
	// 			continue;
	// 		ans+=(Arr[i+1]-1);
	// 		Arr[i]=Arr[i+1]-1;
	// 		if(Arr[i]==1)
	// 			break;
	// 	}
	// 	//cout<<ans<<endl;
	// }

	cout<<ans<<endl;		
}