#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,x,y;
	cin>>n>>x>>y;
	lli arr[n];
	for(lli i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(x<=y)
	{
		lli u=upper_bound(arr,arr+n,x)-arr;
		if(u%2==0)
			cout<<u/2<<endl;
		else
			cout<<u/2+1<<endl;
		return 0;
	}
	else if(x>y)
	{
		cout<<n<<endl;
		return 0;
	}
}