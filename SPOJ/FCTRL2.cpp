#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli fact[300];
lli carry;
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
		lli fact_size=1;
		carry=0;
		fact[0]=1;
		for(lli i=2;i<=N;i++)
		{
			for(lli j=0;j<fact_size;j++)
			{
				lli x=fact[j]*i+carry;
				fact[j]=x%10;
				carry=x/10;
			}
			if(carry!=0)
			{
				while(carry!=0)
				{
					fact_size++;
					fact[fact_size-1]=carry%10;
					carry=carry/10;
				}
				
			}
		}

		for(lli i=fact_size-1; i>=0;i--)
		{
			cout<<fact[i];
		}
		cout<<endl;
	}
}