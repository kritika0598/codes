#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Lazy[100005];
lli Arr[100005];
lli tree[100005];

void update(lli node, lli start, lli end, lli l, lli r, lli val)
{
	if(Lazy[node]!=0)
	{
		tree[node]+=(end-start+1)* Lazy[node];
		if(start!=end)
		{
			Lazy[2*node]=Lazy[2*node]+Lazy[node];
			Lazy[2*node+1]+=Lazy[node];
		}
		Lazy[node]=0;
		
	}
	if(start>r || end<l || start> end)
		return;

	if(start>=l && end <=r)
	{
		tree[node]+=(end-start+1)*val;
		if(start!=end)
		{
			Lazy[2*node]+=val;
			Lazy[2*node+1]+=val;
		}
		return;
	}

	lli mid=(start+end)/2;
	update(2*node, start, mid,l,r,val);
	update(2*node+1, mid+1, end, l, r , val);

	tree[node]=tree[2*node]+tree[2*node+1];
}

lli query(lli node, lli start, lli end, lli l, lli r)
{
	if(Lazy[node]!=0)
	{
		tree[node]+=(end-start+1)* Lazy[node];
		if(start!=end)
		{
			Lazy[2*node]=Lazy[2*node]+Lazy[node];
			Lazy[2*node+1]+=Lazy[node];
		}
		Lazy[node]=0;
		
	}
	if(start>r || end<l || start> end)
		return 0;
	if(start>=l && end<=r)
	{
		return tree[node];
	}

	int mid=(start+end)/2;
	lli p1= query(2*node, start, mid, l, r);
	lli p2= query(2*node +1, mid+1, end, l, r);

	return (p1+p2);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--)
	{
		lli n,u;
		cin>>n>>u;
		memset(Lazy,0,sizeof(Lazy));
		memset(Arr,0,sizeof(Arr));
		memset(tree,0,sizeof(tree));
		for(lli i=0;i<u;i++)
		{
			lli l,r,val;
			cin>>l>>r>>val;
			update(1,1,n,l+1,r+1,val);
		}
		lli q;
		cin>>q;
		vector<lli> :: iterator itr;
		for(lli i=0;i<q;i++)
		{
			lli x;
			cin>>x;
			cout<<query(1,1,n,x+1,x+1)<<endl;
		}
	}
}