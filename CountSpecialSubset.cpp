
// C++ program to find prime factorization of a 
// number n in O(Log n) time with precomputation 
// allowed. 
#include "bits/stdc++.h" 
using namespace std; 
  
#define MAXN   1000001 

typedef long long int lli;
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 
  
// driver program for above function 
int main() 
{ 
    // precalculating Smallest Prime Factor 
    sieve(); 
    lli t;
    cin>>t;
    while(t--)
    {
    	lli n,x;
    	cin>>n>>x;
    	lli arr[n];
    	for(lli i=0;i<n;i++)
    	{
    		cin>>arr[i];
    	}
    	//vector <int> p = getFactorization(x);
    	vector<lli> z;
    	
    	bool flag=false;
    	for(lli j=0;j<n;j++)
    	{
    		vector <int> p = getFactorization(arr[j]);
    		lli y= p.size();
    		flag=false;
    		for(lli i=0;i<y;i++)
    		{
    			if(x%p[i]!=0)
    			{
    				flag=true;
    				break;
    			}
    		}
    		if(!flag)
    		{
    			z.push_back(arr[j]);
    		}

    	}

    	lli y=z.size();
    	
    	
    }
    int x = 12246; 
    cout << "prime factorization for " << x << " : "; 
  
    // calling getFactorization function 
     
  
    for (int i=0; i<p.size(); i++) 
        cout << p[i] << " "; 
    cout << endl; 
    return 0; 
} 
