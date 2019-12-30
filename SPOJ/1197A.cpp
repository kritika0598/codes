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
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}
		sort(Arr,Arr+N);
		lli ans=0;
		ans=Arr[N-2]-1;
		lli x=0;
		for(lli i=0;i<N-2;i++)
		{
			if(Arr[i]!=0)
			{
				x++;
			}
			if(x>ans)
			{
				x=ans;
				break;
			}
			if(x==ans)
			{
				break;
			}
		}

		cout<<x<<endl;
	}
}