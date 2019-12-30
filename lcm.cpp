#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli cnt=0;

void printDivisors(lli n) 
{ 
    // Note that this loop runs till square root 
    for (lli i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                cnt++; 
  
            else // Otherwise print both 
                cnt=cnt+2;
        } 
    } 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli b;
	cin>>b;
	printDivisors(b);
	cout<<cnt<<endl;
		
}