#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli Arr[N][N];
	for(lli i=0;i<N;i++)
	{
		for(lli j=0;j<N;j++)
		{
			cin>>Arr[i][j];
		}
	}
	cout<<N<<endl;
	for(lli i=0;i<N;i++)
	{
		cout<<i+1<<" "<<1<<" "<<i+1<<" "<<N<<endl;
	}
}