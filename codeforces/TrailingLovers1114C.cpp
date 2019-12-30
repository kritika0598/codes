#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll,ll> m;
map<ll,ll> v;
map<ll,ll> :: iterator i;
void largestPower(ll n, ll p) 
{ 
    // Initialize result 
    ll x = 0; 
  
    // Calculate x = n/p + n/(p^2) + n/(p^3) + .... 
    while (n) 
    { 
        n /= p; 
       	x += n; 
    } 
    m[p]=x; 
}  

void primeFactors(ll n) 
{ 
    // Print the number of 2s that divide n 
    while(n%2 == 0) 
    { 
     //   v.push_back(2);
     //   while(n%2==0)
        {
        	 n = n/2; 
        }
        v[2]++; 
       
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
       // if(n%i==0)
        {
        	//v.push_back(i);
        	while (n%i == 0) 
	        { 
	            //printf("%d ", i); 
	            v[i]++;
	            n = n/i; 
	        } 
        }
        
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2)
    	//v.push_back(n); 
    	v[n]++;
        //printf ("%d ", n); 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll N,b;
	cin>>N>>b;
	ll ans=1ll<<60;
	//ll ans=1ll<<60;
	//rem=0;
	primeFactors(b);

	for(i=v.begin();i!=v.end();i++)
	{
		largestPower(N,i->first);
		ll q=m[i->first]/(i->second);
		//if(q>0)
		ans=min(ans,q);
	
	}

	if(ans==(1ll<<60))
		ans=0;
	cout<<ans<<endl;
	return 0;
}