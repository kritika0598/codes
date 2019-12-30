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
	lli maxi=0;
	lli maxi2=0;
	lli sum=0;
	lli z=0;
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
		sum=sum+Arr[i];
		if(Arr[i]>=maxi)
		{
			//maxi2=maxi;
			maxi=Arr[i];
			z=i;
		}	

	}
	for(lli i=0;i<N;i++)
	{
		if(i!=z)
		{
			if(Arr[i]>maxi2)
				maxi2=Arr[i];
		}
	}
	bool flag=true;
	vector<lli> v;
	lli count1=0;
	for(lli i=0;i<N;i++)
	{
		if(Arr[i]==maxi)
		{
			if(sum-Arr[i]-maxi2==maxi2)
			{
				//cout<<i<<" ";
				v.push_back(i);
				count1++;
				flag=false;
			}	
		}
		else
		{
			if(sum-Arr[i]-maxi==maxi)
			{
			//	cout<<i<<" ";
				v.push_back(i);
				count1++;
				flag=false;
			}	
		}
	}

	if(flag)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<count1<<endl;
	for(lli i=0;i<count1;i++ )
	{
		cout<<v[i]+1<<" ";
	}
	cout<<endl;
	return 0;	
}