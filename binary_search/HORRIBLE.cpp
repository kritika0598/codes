#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli tree[1000005];
lli arr[1000005];
lli lazy[1000005];


void update(lli node,lli start,lli end,lli l,lli r,lli val)
{
	//cout<<"hello"<<endl;
	if(lazy[node]!=0)
	{
		tree[node]=tree[node]+((end-start+1)*lazy[node]);
		if(start!=end)
		{
			lazy[2*node]=lazy[2*node]+lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l)
	{
		return ;
	}
	if(start>=l && end<=r)
	{
		tree[node]+=(end-start+1)*val;
		if(start!=end)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return ;
		//cout<<"wow"<<endl;
	}

	int mid=(start+end)/2;
	update(2*node,start,mid,l,r,val);
	update(2*node+1,mid+1,end,l,r,val);
	tree[node]=tree[2*node]+tree[2*node+1];
}

lli query(lli node, lli start,lli end,lli l,lli r )
{
	if(start>end || start>r || end<l)
	{
		return 0;
	}
	if(lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r)
	{
		return tree[node];
	}
	lli mid=(start+end)/2;
	lli p1=query(2*node,start,mid,l,r);
	lli p2=query(2*node+1,mid+1,end,l,r);
	return (p1+p2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	lli N,C;
	cin>>T;
	while(T--)
	{
		cin>>N>>C;
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		lli t,l,r,v;
		for(lli i=0;i<C;i++)
		{
			cin>>t;
			if(t==0)
			{
				cin>>l>>r>>v;
				update(1,1,N,l,r,v);
			}
			else
			{
				cin>>l>>r;
				cout<<query(1,1,N,l,r)<<endl;
			}
		}

	}
		
}