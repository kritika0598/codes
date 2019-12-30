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
	lli n,k;
	while(T--)
	{
		cin>>n>>k;
		//k--;
		lli arr[n+1];
		for(lli i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,greater<lli>());
		lli ans=k;
		while(1)
		{
			if(arr[k]==arr[k-1])
			{
				ans++;
				k++;
			}
			else
				break;	
		}
		cout<<ans<<endl;
	}
		
}