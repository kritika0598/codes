#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	vector<lli> x;
	vector<lli> :: iterator u,l;
	if(K>N)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	lli i=1;
	while(i<=N)
	{
		x.push_back(i);
		i=i*2;
	}

	// for(lli j=0;j<x.size();j++)
	// {
	// 	cout<<x[j]<<" ";
	// }
	// cout<<endl;
	
	lli nearest =x[x.size()-1];
	//cout<<nearest<<endl;
	lli Arr[K];
	for(lli j=0;j<K;j++)
	{
		Arr[j]=1;
	}
	// if(N-nearest+1==K)
	// {
	// 	Arr[K-1]=nearest;
	// }
	
	lli k=x.size()-2;
	while(N-nearest+1<K)
	{
		nearest=x[k];
		k--;
	}
	//cout<<nearest<<endl;
	lli sum=0;
	lli ind=K-1;
	Arr[K-1]=nearest;
	sum=sum+Arr[ind];
	while(ind!=0 && sum!=N)
	{
		lli p=N-sum+(K-ind+1)-K;
		//cout<<p<<endl;
		ind--;
		u=upper_bound(x.begin(),x.end(),p);
		l=lower_bound(x.begin(),x.end(),p);
		if(u!=l)
		{
			nearest=*l;
		}
		else
		{
			nearest=*(l-1);
		}
		Arr[ind]=nearest;
		sum=sum+Arr[ind];

	}
	sum=0;
	for(lli j=0;j<K;j++)
	{
		sum=sum+Arr[j];
	}
	if(sum==N)
	{
		cout<<"YES"<<endl;
	}
	else 
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(lli j=0;j<K;j++)
	{
		cout<<Arr[j]<<" ";
	}
	cout<<endl;

}