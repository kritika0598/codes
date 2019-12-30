#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli tree[1000005];
bool lazy[1000005];
lli Arr[100005];
void update(lli node, lli start, lli end, lli l, lli r )
{
	if(lazy[node])
	{
		lazy[node]=false;
		tree[node]=end-start+1 -tree[node];
		if(start!=end)
		{
			lazy[2*node]=!lazy[2*node];
			lazy[2*node+1]=!lazy[2*node+1];
		}
	}

	if(start>end || start>r || end<l)
		return;

	if(start>=l && end<=r)
	{
		tree[node]=end-start+1-tree[node];
		if(start!=end)
		{
			lazy[2*node]=!lazy[2*node];
			lazy[2*node+1]=!lazy[2*node+1];
		}
		return;
	}

	lli mid=(start+end)/2;
	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);

	tree[node]=tree[2*node]+tree[2*node+1];

}


lli query(lli node, lli start, lli end, lli l, lli r)
{
	if(start>end || start>r || end<l)
		return 0;

	if(lazy[node])
	{
		lazy[node]=false;
		tree[node]=end-start+1 -tree[node];
		if(start!=end)
		{
			lazy[2*node]=!lazy[2*node];
			lazy[2*node+1]=!lazy[2*node+1];
		}
	}

	if(start>=l && end<=r)
	{
		return tree[node];
	}
	lli mid=(start+end)/2;

	lli p1 = query(2*node,start,mid,l,r);
	lli p2= query(2*node+1,mid+1,end,l,r);

	return (p1+p2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	lli N,M;
	cin>>N>>M;
	while(M--)
	{
		lli t,l,r;
		cin>>t>>l>>r;
		if(t==0)
		{
			update(1,1,N,l,r);
		}
		else
		{
			cout<<query(1,1,N,l,r)<<endl;
		}
	}

	return 0;
}