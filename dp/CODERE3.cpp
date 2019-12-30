#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;



lli foo( lli arr[], lli n )  
{  
	//cout<<"hello"<<endl;
    lli lis[n];
    lli lds[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in bottom up manner */
    for (lli i = 1; i < n; i++ )  
    { 
    	
        lis[i] = 1; 
        for (lli j = 0; j < i; j++ )   
        {
        	//cout<<"hello2"<<endl;
        	if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1; 
        }     
    }
    lds[n-1]=1;
    for(lli i=n-2;i>=0;i--)
    {
    	lds[i]=1;
    	for(lli j=n-1;j>i;j--)
    	{
    		if(arr[i]>arr[j] && lds[i]<lds[j]+1)
    			lds[i]=lds[j]+1;
    	}
    } 
  
    // Return maximum value in lis[]
    lli maxi=1; 
    for(lli i=0;i<n;i++)
    {
    	if(lds[i]+lis[i]-1>maxi)
    		maxi=lds[i]+lis[i]-1;
    }
   // cout<<"hello"<<endl;
    return maxi;
}  
    


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		lli Arr[N];
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}

		cout<<foo(Arr,N)<<endl;
	}
		
}
