/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string pattern, text;

	cin>>pattern>>text;
	int p=pattern.length();
	string s=pattern+"$"+text;
	int N=s.length();
	int Z[N];
	Z[0]=0;
	int left=0,right=0;
	int cnt=0;
	for(int k=1;k<N;k++)
	{
	    if(right<k)
	    {
	        right=left=k;
	        while(right<N && s[right]==s[right-left])
	        {
	            right++;
	        }
	        Z[k]=right-left;
	        right--;
	    }
	    else
	    {
	        int k1=k-left;
	        if(Z[k1]<right-k+1)
	        {
	            Z[k]=Z[k1];
	        }
	        else
	        {
	            left = k;
                while (right < N && s[right-left] == s[right]) 
                {
                    right++;
                }
                Z[k] = right-left; 
                right--;
	        }
	    }
	    //cout<<Z[k]<<endl;
	    
	    if(Z[k]==p)
	    {
	        cnt++;
	    }
	}
	cout<<cnt<<endl;
}