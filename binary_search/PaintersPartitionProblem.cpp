#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
	    lli k,n;
	    cin>>k>>n;
	    lli Arr[n];
	    lli sum=0;
	    lli maxi=0;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>Arr[i];
	        sum+=Arr[i];
	        if(Arr[i]>maxi)
	            maxi=Arr[i];
	    }
	    
	    lli low=maxi;
	    lli high=sum;
	    
	    while(low<high)
	    {
	        lli mid=(low+high)/2;
	        lli current_load=0;
	        lli req=1;
	        for(lli i=0;i<n;i++)
	        {
	            if(current_load+Arr[i]<=mid)
	            {
	                current_load+=Arr[i];
	            }
	            else
	            {
	                ++req;
	                current_load=Arr[i];
	            }
	        }
	        
	        if(req<=k)
	        {
	            high=mid;
	        }
	        else
	        {
	            low=mid+1;
	        }
	    }
	    cout<<low<<endl;
	}
}