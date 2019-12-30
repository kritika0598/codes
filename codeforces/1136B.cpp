#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;
	cout<<n*3+min(k-1,n-k)<<endl;
	// if(n%2==0)
	// {
	// 	//if(k<=n/2)
	// 	{
	// 		cout<<n*3+k-1<<endl;
	// 	}
	// 	else
	// 	{
	// 		k=k%n+1;
	// 		cout<<n*3+k-1<<endl;
	// 	}
	// }
	// else
	// {
	// 	if(k<=n/2+1)
	// 	{
	// 		cout<<n*3+k-1<<endl;
	// 	}
	// 	else
	// 	{
	// 		k=k%n+1;
	// 		cout<<n*3+k-1<<endl;
	// 	}
	// }
	
}