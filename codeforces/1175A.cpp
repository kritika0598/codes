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
		lli N,K;
		cin>>N>>K;
		lli ans=0;
		while(N)
		{
			//cout<<N<<" "<<ans<<endl;
			if(N%K==0)
			{
				N=N/K;
				ans++;
			}
			else
			{
				lli a=(N%K);
				ans+=a;
				N=N-a;
			//	N=N/K;
			}

		}

		cout<<ans<<endl;
	}
}