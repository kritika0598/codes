#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli maxSubArraySum(lli a[], lli size) 
{ 
    lli max_so_far = INT_MIN, max_ending_here = 0; 
  	lli l=0,r=0;
    for (lli i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here)
        {
        	max_so_far = max_ending_here; 
        }  
        if (max_ending_here < 0)
        {
        	max_ending_here = 0;
        }             
    } 
    return max_so_far; 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m;
	cin>>n>>m;
	lli Arr[n];
	lli sum=0;
	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
		sum+=Arr[i];
	}

	if(m>0)
	{
		lli x=maxSubArraySum(Arr,n);
		sum=sum-x;
	}
}