#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli c=0;

void canPairs(lli arr[], lli n, lli k) 
{ 

    // Create a frequency array to count occurrences 
    // of all remainders when divided by k. 
    map<lli, lli> freq; 
  
    // Count occurrences of all remainders 
    for (int i = 0; i < n; i++) 
        freq[arr[i] % k]++; 
  
    // Traverse input array and use freq[] to decide 
    // if given array can be divided in pairs 
    for (int i = 0; i < n; i++) 
    { 
        // Remainder of current element 
        lli rem = arr[i] % k; 
		if (rem == 0) 
        { 
        	c=c+(freq[rem]/2);
        	if(freq[rem]%2==0)
           {
           		
           		freq[rem]=0;
           }
           else
           {
           		freq[rem]=1;
           }
         //  cout<<"h2 "<<c<<" "<<rem<<" "<<freq[rem]<<endl;

        }         
  
        // Else number of occurrences of remainder 
        // must be equal to number of occurrences of 
        // k - remainder 
        else if (freq[rem]!=0 && freq[k - rem]!=0)
        {
        	lli x=min(freq[rem],freq[k-rem]);
        	
        	if(rem!=k-rem)
        	{
        		c=c+(x);
       	    	freq[rem]=freq[rem]-x;
        		freq[k-rem]=freq[k-rem]-x;
        	}
        	else
        	{
        		c=c+(x/2);
        		freq[rem]=freq[rem]-x;
        	}

        	//cout<<"h1 "<<c<<" "<<rem<<" "<<freq[rem]<<" "<<freq[k-rem]<<endl;
        } 

       // cout<<arr[i]<<" "<<c<<endl;
    }  
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	lli Arr[N+1];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	sort(Arr,Arr+N);
	canPairs(Arr, N,K);
	cout<<2*c<<endl;

}
