#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
bool prime[MAX];
int sp[MAX];
int main()
 {

int i,j,k,n,tc;	
	
	for(i=2;i<MAX;i++)
	{
	    prime[i]=true;
	    sp[i]=0;
	}
	
	for(i=2;i<=MAX;i++)
	{
	    if(prime[i]==true)
	    {
	        k=2;
	        for(j=i;j*k<=MAX;k++)
	        prime[j*k]=false;
	    }
	}
	
	for(i=3;i<=MAX;i++)
	{
	    if(prime[i]==false)
	    continue;
	    else
	    {
	        if(prime[i+2]==1)
	        sp[i+2]=1;
	    }
	}
	
	for(i=6;i<=MAX;i++)
	sp[i]=sp[i-1]+sp[i];
	
	
	scanf("%d",&tc);
	while(tc-->0)
	{
	    scanf("%d",&n);
	    
	    printf("%d\n",sp[n]);
	}
	return 0;
}