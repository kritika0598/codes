#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
map<lli,lli> compress;
pair<lli,lli> points[1000005];
pair<pair<lli,lli>,lli> que[1000005];
lli Arr[1000005];
lli tree[1000005];
lli lazy[1000005];
lli Ans[1000005];
void update(lli node, lli start, lli end, lli l, lli r, lli val)
{
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		
		if(start!=end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1]+= lazy[node]; 
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l)
		return;
	if(start>=l && end<=r)
	{
		tree[node]+=val;
		if(start!=end)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
	//	lazy[node]=0;
		// if(start==end)
		// {
		// 	tree[node]+=val;
		// 	Arr[start]=tree[node];
		// }
		return;
	}

	lli mid=(end+start)/2;
	update(2*node, start, mid, l,r,1);
	update(2*node+1, mid+1, end, l,r ,1);
	tree[node]=max(tree[2*node],tree[2*node+1]);
	return;
	//tree[node]=(tree[2*node]+tree[2*node+1]);
}

lli query(lli node, lli start, lli end, lli l, lli r)
{
	if(start>end || start>r || end<l)
		return 0;

	if(lazy[node]!=0)
	{
		//if(start==end)
		{
			tree[node]+=lazy[node];
		}
		//tree[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1]+= lazy[node]; 
		}
		lazy[node]=0;
	}

	if(start>=l && end<=r)
		return tree[node];

	lli mid=(start+end)/2;
	lli p1=query(2*node,start,mid,l,r);
	lli p2=query(2*node+1, mid+1, end,l,r );

	return max(p1,p2);
	//return p1+p2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,Q;
	cin>>N;
	lli L,R;
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));

	for(lli i=1;i<=N;i++)
	{
		//cin>>L>>R;
		cin>>points[i].first>>points[i].second;
		//compress[L]=compress[R]=1;
		compress[points[i].first]=compress[points[i].second]=1;
	}
	cin>>Q;
	for(lli i=1;i<=Q;i++)
	{
		cin>>que[i].first.first>>que[i].first.second;
		que[i].second=i;
		compress[que[i].first.first]=compress[que[i].first.second]=1;
	}
	lli a=0;
	for(auto &x: compress)
		x.second=a++;

	for(lli i=1;i<=N;i++)
	{
		update(1,1, a, compress[points[i].first],compress[points[i].second],1);
	}
	for(lli i=1;i<=Q;i++)
	{
		Ans[que[i].second]=query(1,1,a,compress[que[i].first.first],compress[que[i].first.second]);
	}

	for(lli i=1;i<=Q;i++)
	{
		cout<<Ans[que[i].second]<<endl;
	}
	

}