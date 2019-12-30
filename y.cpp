/*#include<iostream>
#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long int lli;




lli tree[3*MAX]; //a segment tree is nearly twice as large as the array.
lli arr[MAX];

void build(lli n, lli b, lli e)
{
     if (b>e) return;
     else if (b==e)
     {
      tree[n] = arr[b];
      return;
     }
    
     build ( n*2 , b , (b+e)/2 );
    
    build (n*2+1, (b+e)/2 + 1 , e );
    tree[n] =( tree[n*2] + tree[n*2 + 1] );

}



void update(lli n, lli b, lli e, lli idx, lli val)
{

    if(val== 0)
        return;

        AID = AID + VAL

    if(idx==n)
        update(n,b,e,1, VAL - 1)

        else :

            UPDATE(ID + 1, VAL - 1)
    
    
    
 if ( b>idx || e<idx ) return;
 if (val==0) //at leaf node
 {
  tree[n] =tree[n]+ val;
  val--;
  idx++;
  return;
 }
 if(idx==n)
    update(n*2,1,e,)

 update( n*2 , b , (b+e)/2 , idx, val );
 update( n*2 + 1 , (b+e)/2 + 1 , e , idx, val );

 //now some change might have been made in either of the child nodes.

 tree[n] = max( tree[n*2] , tree[n*2 + 1] );

}

*/







#include <bits/stdc++.h>
#define f(i,a,b) for (int i = a; i <= b; i++)
#define mod 1000000007;
using namespace std;
typedef long long int lli;

const lli RIGHT =300005;
const lli SIZE = 300005;
lli N, Q, K[SIZE], D[SIZE], LK[SIZE], LD[SIZE], S[SIZE];

lli query(lli l, lli r, lli n = 1, lli a = 1, lli b = RIGHT)
{
    if(a > r || b < l) return 0;
    if(a >= l && b <= r) return S[n];

    if(LK[n] != 0 || LD[n] != 0)
    {
        lli sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }

    lli mid = (a+b) / 2;
    return query(l,r,2*n,a,mid) + query(l,r,2*n+1,mid+1,b);
}

void update(lli l, lli r, lli k, lli d, lli n = 1, lli a = 1, lli b = RIGHT)
{
    if(a >= l && b <= r)
    {
        K[n] += k, D[n] += d;
        LK[n] += k, LD[n] += d;
        lli sz = (b-a+1);
        S[n] += k*sz + d*sz*(sz-1) / 2;
        return;
    }

    if(LK[n] != 0 || LD[n] != 0)
    {
        lli sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }

    lli mid = (a+b) / 2;
    lli z=0;
    if(l <= mid) update(l,min(mid,r),k,d,2*n,a,mid);
    if(r > mid) update(max(mid+1,l),r,k + d*(max(mid-l+1,z)),d,2*n+1,mid+1,b);

    S[n] = S[2*n] + S[2*n+1];
}

int main()
{
    cin>>N>>Q;
    for(lli i=1;i<=N;i++)
    {
        cin>>S[i];
    }
    while(Q--)
    {
        int t;
        scanf("%d", &t);
        if(t == 1)
        {
            lli l,r,k,d;
            lli ID,VAL;
            cin>>ID>>VAL;
            l=ID;
            
            lli x=VAL/N;
            lli y=VAL%N;
            lli z=0;
            for(lli i=0;i<x;i++)
            {
                z=z+(VAL-i*N);
            }
            lli m=0;
            lli b=VAL-(N-ID+1);
            
            for(lli i=0;i<x;i++)
            {
                m=m+(b-i*N);
            }
            update(l,N,z,-x);
            update(1,l-1,b,-x);
            if(y!=0)
            {
                l=ID;
                if(N-ID+1>=y)
                    update(l,ID+y-1,y,-1);
                else
                {
                    update(l,N,y,-1);
                    y=y-(N-ID+1);
                    update(1,y,y,-1);
                }
            }
            
        }
        else
        {
            lli l,r;
            cin>>l>>r;
            lli x=0;
            
            if(l<=r)
                x=x+query(l,r);
            else
            {
                x=x+query(l,N);
                x=x+query(1,r);
            }
            cout<<x<<endl;
        }
    }
}

