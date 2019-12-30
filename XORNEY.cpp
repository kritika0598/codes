#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli computeXOR(lli n) 
{  
  
    switch(n & 3) // n % 4  
    { 
    case 0: return n;     
    case 1: return 1;       
    case 2: return n + 1;      
    case 3: return 0;    
    } 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli a,b;
		cin>>a>>b;
		if(a==1)
		{
			lli x=computeXOR(b);
			if(x%2==0)
				cout<<"Even"<<endl;
			else
				cout<<"Odd"<<endl;
		}
		else
		{
			lli x= computeXOR(a-1) ^ computeXOR(b);
			if(x%2==0)
				cout<<"Even"<<endl;
			else
				cout<<"Odd"<<endl;
		}
		
	}
	return 0;
		
}