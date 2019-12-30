#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli BIT[100005];
lli N;
void update(lli ind, lli val)
{
	while(ind<=N)
	{
		BIT[ind]+=val;
		ind+=ind&(-ind);
	}
}

lli query(lli ind)
{
	lli ans=0;
	while(ind>=1)
	{
		ans+=BIT[ind];
		ind-=ind&(-ind);
	}
	return ans;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--)
	{
		//lli N;
		cin>>N;
		memset(BIT,0,sizeof(BIT));
		map<string, lli> m1;
		map<string, lli> m2;
		map<string, lli> :: iterator itr;
		string S1;
		string S2;

		lli Arr[N+1];
		lli Arr1[N+1];
		string z[N+1];
		lli k=0;
		for(lli i=1;i<=N;i++)
		{
			Arr[i]=i;
		}

		for(lli i=1;i<=N;i++)
		{
			cin>>S1;
			z[i]=S1;
		//	m1[S1]=i;
		}

		for(lli i=1;i<=N;i++)
		{
			cin>>S1;
			m2[S1]=i;
		}
		
		for(lli i=1;i<=N;i++)
		{
			Arr1[i]=m2[z[i]];
		//	cout<<Arr1[i]<<endl;
		}

		lli ans=0;
		for(lli i=1;i<=N;i++)
		{
			lli pos=lower_bound(Arr+1, Arr+N+1, Arr1[i])-Arr;
			ans=ans+query(N)-query(pos);
		//	cout<<ans<<" "<<pos<<" "<<query(N)<<" "<<query(pos)<<endl;
			update(pos,1);

		}
		cout<<ans<<endl;

	}
		
}