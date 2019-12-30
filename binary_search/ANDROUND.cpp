#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[20005];
lli tree[2000005];
void build(lli node, lli start, lli end)
{
	if(start==end)
	{
		tree[node]=Arr[start];
	}
	else
	{
		lli mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);

		tree[node]=tree[2*node]&tree[2*node+1];
	}
	return;
}


lli query(lli node, lli start, lli end, lli l, lli r)
{
	if(start>end || start>r || end<l)
		return (pow(2,30)-1);

	if(start>=l && end<=r)
	{
		return tree[node];
	}

	lli mid=(start+end)/2;
	lli p=query(2*node,start,mid,l,r);
	lli q=query(2*node+1,mid+1,end,l,r);
	return p&q;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,K;
		cin>>N>>K;
		memset(Arr,0,sizeof(Arr));
		memset(tree,0,sizeof(tree));
		for(lli i=1;i<=N;i++)
		{
			cin>>Arr[i];
		}

		build(1,1,N);

		for(lli i=1;i<=N;i++)
		{
			if(N/2<=K)
				cout<<query(1,1,N,1,N)<<" ";
			else
			{
				lli x,y,ans;
				if(i+K>N)
				{
					ans=query(1,1,N,i,N);
					x=(i+K)%N;
					ans=ans&query(1,1,N,1,x);
				}
				else
				{
					x=(i+K);
					ans=query(1,1,N,i,x);
				}

				if(i-K<1)
				{
					ans=ans&query(1,1,N,1,i);
					y=N+(i-K);
					ans=ans&query(1,1,N,y,N);
				}
				else
				{
					y=(i-K);
					ans=ans&query(1,1,N,y,i);

				}

				cout<<ans<<" ";
				
			}
		}
		cout<<endl;
	}
}