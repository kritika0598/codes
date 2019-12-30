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
		lli N;
		cin>>N;
		lli arr[N];
		lli s[N+5];
		for(lli i=0;i<N;i++)
		{
			cin>>arr[i];
			if(i==0)
				s[0]=arr[0];
			else
			{
				s[i]=s[i-1]+arr[i];
			}
		}
		lli x=1;
		lli sum=1;
		lli t=0;
		while(sum<N)
		{
			t++;
			sum=sum+s[sum-1];
			x=sum;
		}
		cout<<t<<endl;
	}
		
}