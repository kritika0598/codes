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
		lli arr[N+1];
		lli A[N+1];
		map<lli,lli>m;
		map<lli,lli>z;
		for(lli i=1;i<=N;i++)
		{
			cin>>arr[i];
			m[arr[i]]++;
		}
		map<lli,lli> :: iterator it;
		bool flag=false;
		for(it=m.begin();it!=m.end();++it)
		{
			lli f=it->first;
			m[f]=arr[f];
			z[m[f]]++;
			if(z[m[f]]>1)
			{
				flag=true;
			}
		}
		if(flag)
		{
			cout<<"Truly Happy"<<endl;
		}
		else
		{
			cout<<"Poor Chef"<<endl;
		}
	}
		
}