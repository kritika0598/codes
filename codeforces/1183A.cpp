#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a;
	cin>>a;
	lli x=a;
	lli sum=0;
	while(x!=0)
	{
		sum+=(x%10);
		x=x/10;
	}

	if(sum%4==0)
	{
		cout<<a<<endl;
	}
	else
	{
		lli i=1;
		while(1)
		{
			x=a+i;
			lli q=x;
			sum=0;
			while(x!=0)
			{
				sum+=(x%10);
				x=x/10;
			}
			if(sum%4==0)
			{
				cout<<q<<endl;
				break;
			}
			i++;
		}
	}
}