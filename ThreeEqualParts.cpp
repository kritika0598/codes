#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		lli Arr[N];
		lli cnt=0;
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
			if(Arr[i]==1)
				cnt++;
		}
		if(cnt%3!=0)
		{
			cout<<-1<<endl;
		}
		else
		{
			
		}
	}
		
}