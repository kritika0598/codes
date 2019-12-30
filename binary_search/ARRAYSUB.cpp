#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Arr[1000005];
lli tree[1000005];


void build(lli node, lli start ,lli end)
{
	if(start==end)
	{
		tree[node]= Arr[start];
		return;
	}
	else
	{
		lli mid=(start+end)/2;
		//lli mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);

		tree[node] = max(tree[2*node],tree[2*node+1]);
		return;
	}
	
}

lli query(lli node, lli start, lli end, lli l, lli r)
{
	if( start>r || end<l)
		return INT_MIN;
	if(l<=start && end<=r)
		return tree[node];
	lli mid=(start+end)/2;
	lli p1=query(2*node,start,mid,l,r);
	lli p2= query(2*node+1,mid+1,end,l,r);
	return max(p1,p2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	memset(tree,0,sizeof(tree));
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
	}
	//	cout<<"hello"<<endl;
	build(1,1,N);

	// for(lli i=0;i<30;i++)
	// {
	// 	cout<<tree[i]<<endl;
	// }
	lli k;
	cin>>k;
	//cout<<query(1,0,N-1,0,0)<<" ";
	for(lli i=1;i<=N-k+1;i++)
	{
		cout<<query(1,1,N,i,i+k-1)<<" ";
	}
	cout<<endl;
}