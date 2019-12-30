// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// typedef long long int lli;
// lli Arr[100005];
// lli lookup[100005][20];
// //lli lookup[1000005][20];

// void build(lli N)
// {
// 	for(lli i=0;i<N;i++)
// 	{
// 		lookup[i][0]=Arr[i];
// 	}

// 	for(lli j=1;(1<<j)<=N;j++)
// 	{
// 		for(lli i=0;(i+(1<<j))<=N;i++)
// 		{
// 			lookup[i][j]=min(lookup[i][j-1],lookup[i+(1<<(j-1))][j-1]);
// 		}
// 	}
// }

// lli query(lli l, lli r)
// {
// 	lli j=floor(log2(r-l+1));

// 	return min(lookup[l][j],lookup[r-(1<<j)+1][j]);
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	lli k=1;
// 	lli N;
// 	//cin>>N;
// 	while(scanf("%lld",&N)!=EOF)
// 	{

// 		memset(Arr,0,sizeof(Arr));
// 		memset(lookup,0,sizeof(lookup));
// 		for(lli i=0;i<N;i++)
// 		{
// 			cin>>Arr[i];
// 		}
// 		build(N);
// 		map<lli,lli> m;
// 		map<lli,lli> :: iterator itr;

// 		lli ans=0;
// 		for(lli i=0;i<N;i++)
// 		{
// 			//cout<<Arr[i]<<endl;
// 			if(Arr[i]==0)
// 			{
// 				for(itr=m.begin();itr!=m.end();itr++)
// 				{
// 					itr->second=0;
// 				}
// 			}
// 			else
// 			{

// 				if(m[Arr[i]]==0)
// 				{
// 					//cout<<Arr[i]<<endl;
// 					ans++;
// 					m[Arr[i]]=i+1;
// 				}
// 				else
// 				{
// 					lli x=query(m[Arr[i]],i-1);
// 					if(x<Arr[i])
// 					{
// 						ans++;
// 						m[Arr[i]]=i+1;
// 					}
// 				}
// 			}
// 		}

// 		cout<<"Case "<<k<<": "<<ans<<endl;
// 		k++;
// 	}
// }


#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<limits.h>
using namespace std;
long long int arr[1000000],segment[2000000];
long long int min(long long int a,long long int b)
{
    return (a>b?b:a);
}
void build( int idx,int i,int j)
{
    if(i==j)
    {
        segment[idx]=arr[i];
        return ;
    }
    int mid=(i+j)/2;
    build(2*idx,i,mid);
    build(2*idx+1,mid+1,j);
    segment[idx]=min(segment[2*idx],segment[2*idx+1]);
}
long long int querry( int idx,int i, int j, int l, int r)
{
    if(i>r || j<l)
    return INT_MAX;
    if(i>=l && j<=r)
    return segment[idx];
    int mid=(i+j)/2;
    int x,y;
    x=querry(2*idx,i,mid,l,r);
    y=querry(2*idx+1,mid+1,j,l,r);
    return min(x,y);
}
int main()
{
int i,n,t=1,ans,m;
long long int min;
while(scanf("%d",&n)!=EOF)
{
    map<int,int> mp;
    ans=0;
    int flag=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i]==0)
            flag=1;
    }
    build(1,1,n);
    for(i=1;i<=n;i++)
    {
            if(!mp[arr[i]])
            {
                ans++;
                mp[arr[i]]=i;
            }   
            else
            {
                m=mp[arr[i]];
                min=querry(1,1,n,m,i);
                if(min<arr[i])
                    ans++;
                mp[arr[i]]=i;
            }
        }
    if(flag)
    ans=ans-1;
    printf("Case %d: %d\n",t,ans);
    t++;
}
return 0;
}