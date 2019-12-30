#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,B,A;
	cin>>N>>B>>A;

	lli Arr[N+1];
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
	}
	lli ans=0;
	lli a=A;
	lli b=B;
	a--;
	ans++;

	for(lli i=2;i<=N;i++)
	{
		if(a==0 && b==0)
		{
			break;
		}
		if(Arr[i]==1)
		{
			if(a==A)
			{
				ans++;
				a--;
			}
			else if(a<A && b!=0)
			{
				a++;
				ans++;
				b--;
			}
			else
			{
				ans++;
				a--;
			}
		}
		else
		{
			if(a!=0)
			{
				a--;
				ans++;
			}
			else
			{
				b--;
				ans++;
			}
		}
	}

	cout<<ans<<endl;
}