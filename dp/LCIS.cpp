#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	//code
	lli T;
	cin>>T;
	while(T--)
	{
	    lli N,M;
	    cin>>N;
	    lli Arr1[N+1];
	    for(lli i=0;i<N;i++)
	    {
	        cin>>Arr1[i];
	    }
	    cin>>M;
	    lli Arr2[M];
	    for(lli i=0;i<M;i++)
	    {
	        cin>>Arr2[i];
	    }
	    
	    lli temp[M];
	    for(lli i=0;i<M;i++)
	    {
	        temp[i]=0;
	    }
	    
	    for(lli i=0;i<N;i++)
	    {
	        lli current=0;
	        for(lli j=0;j<M;j++)
	        {
	            
	            if(Arr1[i]==Arr2[j])
	            {
	                if(current+1>temp[j])
	                {
	                    temp[j]=current+1;
	                }
	            }
	            
	            if(Arr1[i]>Arr2[j])
	            {
	                if(temp[j]>current)
	                   current=temp[j];
	            }
	        }
	    }
	    
	    lli ans=0;
	    for(lli i=0;i<M;i++)
	    {
	        ans=max(ans,temp[i]);
	    }
	    
	    cout<<ans<<endl;
	}
	
	
	return 0;
}