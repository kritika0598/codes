#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
struct node1
{
	//lli val;
	lli maximum;
	lli prefixm;
	lli suffixm;
	lli sum;
}; 
node1 tree[4*50010];
// tree[0].maximum=INT_MIN;
// tree[0].prefixm=INT_MIN;
// tree[0].suffixm=INT_MIN;
// tree[0].sum=INT_MIN;
lli Arr[50015];
void build(lli node,lli start,lli end)
{
	if(start==end)
	{
		tree[node].maximum=Arr[start];
		tree[node].prefixm=Arr[start];
		tree[node].suffixm=Arr[start];
		tree[node].sum=Arr[start];
	}
	else
	{
		lli mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].sum= tree[2*node].sum + tree[2*node+1].sum;
		tree[node].maximum=max(tree[2*node].maximum, max(tree[2*node+1].maximum, tree[2*node].suffixm+tree[2*node+1].prefixm));
		tree[node].prefixm=max(tree[2*node].prefixm, tree[2*node].sum+tree[2*node+1].prefixm);
		tree[node].suffixm=max(tree[2*node+1].suffixm,tree[2*node+1].sum+tree[2*node].suffixm);
	}	
}

void update(lli node,lli start,lli end,lli ind, lli val)
{
	if(start==end)
	{
		Arr[ind]=val;
		tree[node].maximum=val;
		tree[node].prefixm=val;
		tree[node].suffixm=val;
		tree[node].sum=val;
	}
	else
	{
		lli mid=(start+end)/2;
		if(start<=ind && ind<=mid)
			update(2*node,start,mid,ind,val);
		if(ind<=end && ind>mid)
			update(2*node+1,mid+1,end,ind,val);
		tree[node].sum= tree[2*node].sum + tree[2*node+1].sum;
		tree[node].maximum=max(tree[2*node].maximum, max(tree[2*node+1].maximum, tree[2*node].suffixm+tree[2*node+1].prefixm));
		tree[node].prefixm=max(tree[2*node].prefixm, tree[2*node].sum+tree[2*node+1].prefixm);
		tree[node].suffixm=max(tree[2*node+1].suffixm,tree[2*node+1].sum+tree[2*node].suffixm);
	}	
}

node1 query(lli node, lli start, lli end, lli l, lli r)
{

	node1 result;
	result.sum=INT_MIN;
	result.maximum=INT_MIN;
	result.prefixm=INT_MIN;
	result.suffixm=INT_MIN;
	if(r<start || end <l)
		return result;
	if(l<=start && r>=end)
		return tree[node];
	lli mid=(start+end)/2;
	if(l>mid)
		return query(2*node+1,mid+1,end,l,r);
	if(r<=mid)
		return query(2*node,start,mid,l,r);

	node1 left =query(2*node,start,mid,l,r);
	node1 right= query(2*node+1,mid+1,end,l,r);


	result.sum=left.sum+right.sum;
	result.prefixm= max(left.prefixm, left.sum+right.prefixm);
	result.suffixm= max(right.suffixm, right.sum+ left.suffixm);
	result.maximum= max(left.maximum, max(right.maximum, left.suffixm+right.prefixm));
	return (result);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	//lli Arr[N+1];
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
	}
	build(1,1,N);
	lli M;
	cin>>M;
	while(M--)
	{
		lli l,r,t;
		cin>>t>>l>>r;
		if(t==0)
			update(1,1,N,l,r);
		else
		{
			node1 mn=query(1,1,N,l,r);
			cout<<mn.maximum<<endl;
		}
		
	}
}