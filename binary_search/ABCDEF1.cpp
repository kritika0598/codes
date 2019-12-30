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
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	map<lli,lli> m1;
	map<lli,lli> m2;
	map<lli,lli> m3;
	map<lli,lli> m4;

	for(lli i=0;i<N;i++)
	{
		for(lli j=0;j<N;j++)
		{
			m1[Arr[i]+Arr[j]]++;
			m2[Arr[i]*Arr[j]]++;
		}
	}
	map<lli ,lli > :: iterator it1, it2,itlow , itup;

	// for(it1=m1.begin();it1!=m1.end();++it1)
	// {
	// 	cout<<it1->first<<" "<<it1->second<<endl;
	// }
	// for(it2=m2.begin();it2!=m2.end();++it2)
	// {
	// 	cout<<it2->first<<" "<<it2->second<<endl;
	// }
	// cout<<endl;


	for(it1=m1.begin();it1!=m1.end();++it1)
	{
		for(lli i=0;i<N;i++)
		{
			if(Arr[i]!=0)
			{
				m3[(it1->first)*Arr[i]]+=(it1->second);
			}
		}
	}
	for(it2=m2.begin();it2!=m2.end();++it2)
	{
		for(lli i=0;i<N;i++)
		{
			m4[(it2->first)+Arr[i]]+=(it2->second);
		}
	}
	lli ans=0;


	// for(it1=m3.begin();it1!=m3.end();++it1)
	// {
	// 	cout<<it1->first<<" "<<it1->second<<endl;
	// }
	// for(it2=m4.begin();it2!=m4.end();++it2)
	// {
	// 	cout<<it2->first<<" "<<it2->second<<endl;
	// }

	for(it1=m3.begin();it1!=m3.end();++it1)
	{
		lli x=it1->first;
		itlow=m4.lower_bound(x);
		itup=m4.upper_bound(x);
		if(itlow!=itup)
		{
			ans=ans+((it1->second)*(itlow->second));
		}
	}

	cout<<ans<<endl;

}