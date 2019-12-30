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
	vector<pair<lli,lli>> v;
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		lli x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
		Arr[i]=y;
	}

	lli k;
	cin>>k;
	lli x=upper_bound(Arr,Arr+N,k)-Arr;
	lli y=lower_bound(Arr,Arr+N,k)-Arr;

	if(x==y)
		cout<<N-x<<endl;
	else
		cout<<N-x+1<<endl;

}