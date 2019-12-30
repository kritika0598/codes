#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[40000];
lli tree[400000];
lli lazy[400000];

void update(lli Node, lli start, lli end, lli l, lli r, lli val)
{
	if(lazy[Node]!=0)
	{
		tree[Node]=lazy[Node];
		if(start!=end)
		{
			tree[2*Node]=lazy[Node];
			tree[2*Node+1]=lazy[Node];
		}
		lazy[Node]=0;
	}

	if(start>r || end< l || start>end)
		return;
	if(start<=l && end>=r)
	{
		tree[Node]=val;
		if(start!=end)
		{
			Lazy[2*Node]=val;
			Lazy[2*Node+1]=val;
		}
		if(start==end)
		{
			Arr[start]=tree[Node];
		}
		return;
	}	

	lli mid=(start+end)/2;
	update(2*Node,start,mid,l,r,val);
	update(2*Node+1,mid+1,end,l,r,val);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cni>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		memset(Arr,0,sizeof(Arr));
		memset(Lazy,0,sizeof(Lazy));
		memset(tree,0,sizeof(tree));
		set<lli> s;
		for(lli i=1;i<=N;i++)
		{
			lli x,y;
			cin>>x>>y;
			update(1,1,N,x,y,1);
		}

		for(lli i=1;i<=N;i++)
		{
			
		}
	}
}