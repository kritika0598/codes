#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;

	while(k--)
	{
		if(n%10==0)
		{
			n=n/10;
		}
		else
		{
			n=n-1;
		}
	}
	cout<<n<<endl;
}