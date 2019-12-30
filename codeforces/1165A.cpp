#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,x,y;
	cin>>n;
	cin>>x;
	cin>>y;
	string Arr;
	cin>>Arr;
	lli r=n-y-1;
	lli count=0;
	for(lli i=n-1;i>=(n-x);i--)
	{
		if((i==r) && Arr[r]!='1')
			count++;
		else if(i!=r && Arr[i]=='1')
			count++;

	}

	cout<<count<<endl;

}