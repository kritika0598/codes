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
	lli maxi=-1;
	lli ans=1;
	lli x=1;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		if(Arr[i]>maxi)
		{
			maxi=Arr[i];
			x=1;
			ans=1;
		}
		else if(Arr[i]==maxi)
		{
			x++;
			ans=max(ans,x);
		}
		else
		{
			ans=max(ans,x);
			x=0;
		}

	}
	cout<<ans<<endl;
}