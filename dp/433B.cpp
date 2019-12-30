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
	lli cum[N+1];
	lli c[N+1];
	cum[0]=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		{
			cum[i+1]=cum[i]+Arr[i];
		}
	}

	sort(Arr,Arr+N);
	c[0]=0;
	for(lli i=0;i<N;i++)
	{
		c[i+1]=c[i]+Arr[i];
	}

	lli M;
	cin>>M;
	while(M--)
	{
		lli t,l,r;
		cin>>t>>l>>r;
		if(t==1)
		{
			cout<<cum[r]-cum[l-1]<<endl;
		}
		else
		{
			cout<<c[r]-c[l-1]<<endl;
		}
	}

}