#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() 
{

	int T,N,X,S;
	//T=5;
	cin>>T;
	while(T--)
	{
		cin>>N;
		lli arr[N+1];
		memset(arr,0,sizeof(arr));
		cin>>X;
		arr[X]=1;
		cin>>S;
		lli u,v;
		lli temp;
		lli j=X;
		for(lli i=0;i<S;i++)
		{
			cin>>u>>v;
			temp=arr[u];
			arr[u]=arr[v];
			arr[v]=temp;
			if(arr[u]==1)
				j=u;
			if(arr[v]==1)
				j=v;
		}
		cout<<j<<endl;
	}
	return 0;
		
}