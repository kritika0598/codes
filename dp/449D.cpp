/*
// Sample code to perform I/O:
gjtgn
ciuiuyewiun >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
AHEHFUH
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code jhdsfrhgkjrnak

//

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	//cin>>T;
	lli Arr[1000005];
	//lli dp[(1<<20)+5][23];
	lli freq[(1<<22)+5];
	lli F[(1<<22)+5];
	lli MOD=1000000007;
//	while(T--)
	{
	    lli N;
	    cin>>N;
	    memset(A,0,sizeof(A));
	    memset(F,0,sizeof(F));
	   // memset(dp,0,sizeof(dp));
	    for(lli i=0;i<N;i++)
	    {
	        cin>>Arr[i];
	        freq[Arr[i]]++;
	    }
	        
	    for(lli i=0;i<=(1<<22);i++)
	    {
	    	F[i]=freq[i];
	    }

	    for(lli i=0;i<=22;i++)
	    {
	    	for(lli mask=0;mask<=(1<<22);mask++)
	    	{
	    		if(mask&(1<<i))
	    			F[mask]+=F[mask^(1<<i)];
	    	}
	    }
	    lli ans=0;
	    for(lli i=0;i<N;i++)
	    {
	    	ans+=F[(1<<22)-1-Arr[i]];
	    }


	    cout<<endl;
	  //  cout<<ans<<endl;
	}
}
