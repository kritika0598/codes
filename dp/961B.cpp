#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli N,K;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;

	lli Arr[N+1];
	lli cumall[N+1];
	cumall[0]=0;
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		cumall[i]=cumall[i-1]+Arr[i];
	}
	lli cumpart[N+1];
	cumpart[0]=0;
	lli Brr[N+1];
	for(lli i=1;i<=N;i++)
	{
		cin>>Brr[i];
		if(Brr[i]==1)
		{
			cumpart[i]=cumpart[i-1]+Arr[i];
		}
		else
			cumpart[i]=cumpart[i-1];
	}
	lli maxi=cumpart[N];
	for(lli i=1;i<=(N-K+1);i++)
	{
		lli a=cumpart[N]-cumpart[i+K-1]+cumall[i+K-1]-cumall[i-1]+cumpart[i-1];
		//cout<<i<<" "<<a<<endl;
		if(a>maxi)
			maxi=a;
	}

	cout<<maxi<<endl;

	

}