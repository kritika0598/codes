#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli solve(lli N, lli D, lli K, lli i, lli P, lli dis[], lli pet[], lli c)
{
	if(i==D)
		return 0;

	lli x=INT_MAX;
	for(lli j=c+1;j<=N;j++)
	{
		if(dis[j]>=i+P)
		{
			x=min(P+(dis[j]-(i+P))*5+K+solve(N,D,K,dis[j],pet[j],dis,pet,c++),x);
		}
		else
		{
			x=min(x,min(dis[j]+ K + solve(N,D,K,dis[j],pet[j]+P-(dis[j]-i),dis,pet,c++), dis[j]+1+ solve(N,D,K,dis[j]+1,P-(dis[j]+1-i),dis,pet,c++)));
		}
	}
	return x;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N, D, P , K;
	cin>>N>>D>>P>>K;
	lli dis[N+1];
	for(lli i=0;i<N;i++)
	{
		cin>>dis[i];
	}
	dis[N]=D;
	lli pet[N+1];
	for(lli i=0;i<N;i++)
	{
		cin>>pet[i];
	}
	pet[N]=0;
	cout<<solve(N,D,K,0,P, dis, pet, -1 )<<endl;		
}