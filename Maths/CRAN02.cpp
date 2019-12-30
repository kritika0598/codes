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
		lli Arr[N];
		lli psum[N];
		lli ssum[N];
		map<lli,lli> m;
		map<lli,lli> m1;
		lli ans=0;
		bool flag=false;
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];	
			if(i==0)
			{
				psum[0]=Arr[0];
				m[psum[0]]++;	
			}
			else
			{
				psum[i]=Arr[i]+psum[i-1];
				m[psum[i]]++;
			}
		}
		map<lli,lli> :: iterator i;
		for(i=m.begin();i!=m.end();i++)
		{
			lli x,y;
			x=i->first;
			y=i->second;
			if(x==0)
			{
				ans=ans+y+(y*(y-1))/2;
			}
			else
			{
				ans=ans+(y*(y-1))/2;
			}
			
		}
		// ssum[N-1]=Arr[N-2];
		// m1[ssum[N-1]]++;
		// for(lli i=N-2;i>=0;i--)
		// {
		// 	ssum[i]=Arr[i]+ssum[i+1];
		// 	m1[ssum[i]]++;
		// 	if(m1[ssum[i]]>1)
		// 		ans++;
		// }
		// if(flag)
		 	cout<<ans<<endl;
		// else
		// 	cout<<ans-1<<endl;
	}
}