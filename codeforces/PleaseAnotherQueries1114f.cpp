#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int lli;

lli Arr[400005];
lli lazy[1000005];
lli tree[1000005];



void build(lli node, lli start, lli end)
{
	if(start==end)
		tree[node]=Arr[start];
	else
	{
		lli mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=(tree[2*node]%MOD*tree[2*node+1]%MOD)%MOD;
	}
}

void update(lli node, lli start, lli end, lli l,lli r, lli val)
{
	if(lazy[node]!=0)
	{
		tree[node]=tree[node]%MOD*pow(lazy[node],(end-start+1))%MOD;
		if(start!=end)
		{
			lazy[2*node]=lazy[2*node]%MOD*lazy[node]%MOD;
			lazy[2*node+1]=lazy[2*node+1]%MOD*lazy[node]%MOD;
		}
		lazy[node]=0;
	}

	if(start > r || end< l || start>end)
		return;

	if(start>=l && end<=r)
	{
		tree[node]=tree[node]%MOD*pow(val,end-start+1)%MOD;
		if(start!=end)
		{
			lazy[2*node]*=val%MOD;
			lazy[2*node+1]*=val%MOD;
		}
		return ;
	}

	lli mid=(start+end)/2;
	update(2*node,start,mid,l,r,val);
	update(2*node+1,mid+1,end,l,r,val);
	tree[node]=(tree[2*node]%MOD*tree[2*node+1]%MOD)%MOD;
	return;
}

lli query(lli node, lli start, lli end, lli l,lli r)
{
	if(start>r || end<l || start>end)
		return 1;
	if(lazy[node]!=0)
	{
		tree[node]=(tree[node]%MOD*pow(lazy[node],(end-start+1))%MOD);
		if(start!=end)
		{
			lazy[2*node]=lazy[2*node]%MOD*lazy[node]%MOD;
			lazy[2*node+1]=lazy[2*node+1]%MOD*lazy[node]%MOD;
		}
		lazy[node]=0;
	}

	if(start>=l && end<=r)
		return tree[node];

	lli mid=(start+end)/2;
	lli p=query(2*node,start, mid, l,r);
	lli q=query(2*node+1,mid+1,end,l,r);

	return (p*q) %MOD;

}


lli phi(lli n) 
{ 
    double result = n; // Initialize result as n 
  
    // Consider all prime factors of n and for every prime 
    // factor p, multiply result with (1 - 1/p) 
    for (lli p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result *= (1.0 - (1.0 / (double)(p%MOD))); 
        } 
    } 
  
    // If n has a prime factor greater than sqrt(n) 
    // (There can be at-most one such prime factor) 
    if (n > 1) 
        result *= (1.0 - (1.0 / (double)(n%MOD))); 
  
    return (lli)result%MOD; 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,Q;
	cin>>N>>Q;
	memset(lazy,0,sizeof(lazy));
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
	}
	build(1,1,N);
	while(Q--)
	{
		string type;
		cin>>type;
		if(type=="TOTIENT")
		{
			lli l,r;
			cin>>l>>r;
			lli x=query(1,1,N,l,r)%MOD;
			//cout<<x<<endl;
			cout<<phi(x)%MOD<<endl;
		}
		else
		{
			lli l,r,val;
			cin>>l>>r>>val;
			update(1,1,N,l,r,val);
		}
	}
}