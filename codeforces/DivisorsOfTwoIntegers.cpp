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
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	sort(Arr,Arr+N);
	lli a[N];
	lli b[N];
	vector<lli>v;
	lli k=0;
	lli maxi=0;
	for(lli i=0;i<N;i++ )
	{
		if(Arr[i]>maxi)
			maxi=Arr[i];
		if(i!=N-1 && Arr[i]==Arr[i+1] )
		{
			a[k]=Arr[i];
			b[k]=Arr[i];
			k++;
		}
		else{
			v.push_back(Arr[i]);
		}
	}

	lli x,y;
	y=b[k-1];
	x=maxi;
	sort(v.begin(),v.end());

	lli siz=v.size();

	for(lli i=siz-2;i>=0;i--)
	{
		if(x%v[i]!=0)
		{
			y=v[i];
			break;
		}	
	}

	cout<<x<<" "<<y<<endl;

}