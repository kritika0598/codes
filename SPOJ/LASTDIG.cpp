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
		lli a,b;
		cin>>a>>b;
		lli res=1;
		a=a%10;
	//	b=b%10;
		while(b>0)
		{
			if(b&1)
				res=(res*a)%10;
			b=b/2;
			a=(a*a)%10;
		}

		cout<<res%10<<endl;
	}
}