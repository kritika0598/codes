#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m;
	cin>>n>>m;
	lli arr[100005];
	lli x=1;
	for(lli i=1;i<=100000;i++)
	{
		arr[i]=i*(i-1)/2;
		//cout<<i<<" "<<arr[i]<<endl;
		if(arr[i]>=m)
		{
			x=i;
			break;
		}
	}

	lli min=n-2*m;
	if(min<0)
		min=0;
 	if(m==0)
 		cout<<min<<" "<<n<<endl;
 	else
    	cout<<min<<" "<< n-x << '\n'; 
   // cout << "upper_bound for 6 at position " << (upper - v.begin()) << '\n'; 
  
    return 0; 


		
}