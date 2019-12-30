#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[100005];
lli dpf[100005];
lli dpb[100005];
//lli DP[100002][100002][100002];

lli foo(lli start, lli end, lli k)
{
	//return 1;
	if( k==1)
	{
		return max(Arr[start],Arr[end]);
	}
	else
	{
		return max((Arr[start]+foo(start+1,end,k-1)), (Arr[end]+foo(start,end-1,k-1)));
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli K,N;
	cin>>K>>N;
	
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
	}
	
	dpf[0]=0;
	dpb[N+1]=0;
	dpf[1]=Arr[1];
	dpb[N]=Arr[N];

	for(lli i=2;i<=N;i++)
	{
		dpf[i]=dpf[i-1]+Arr[i];
	}
	for(lli i=N-1;i>=1;i--)
	{
		dpb[i]=dpb[i+1]+ Arr[i];
	}

	lli MAXi=-1000000;
	for(lli i=0;i<=K;i++){
		MAXi=max(MAXi,dpf[i]+dpb[N+1-K+i]);
		//cout<<MAXi<<endl;
	}
	cout<<MAXi<<endl;		
}