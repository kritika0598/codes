#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T,N;
	//lli result;
	string Arr[50005];
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(lli i=1;i<=N;i++)
		{
			cout<<1<<" "<<i<<" "<<i<<" "<<i<<endl;
			cin>>Arr[i];
		}
		//cout<<"hello";
		cout<<"2";
		//cout.flush();
		for(lli i=1;i<=N;i++)
		{
			cout<<" "<<Arr[i]<<" ";
			
		}
		cout.flush();
		lli r;
		cin>>r;
		//cout<<r<<" ";
		if(r==-1)
			return 0;
	}
	
}
