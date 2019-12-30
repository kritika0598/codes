#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
//lli x[1000005];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,P;
		cin>>N;
		lli Arr[N];

		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}
		cin>>P;
		sort(Arr,Arr+N);
		lli k=0;
		bool flag=false;
		for(lli i=0;i<N;i++)
		{
			if(!flag)
			{
				for(lli j=i+1;j<N;j++)
				{
					lli x=P-Arr[i]-Arr[j];
					lli l=j+1;
					lli h=N-1;
					while(l<h)
					{
						lli mid=l+(h-l+1)/2;
						if(Arr[mid]>x)
							h=mid-1;
						else
							l=mid;
					}
					if(Arr[l]==x)
					{
						cout<<"YES"<<endl;
						flag=true;
						break;
					}	
					
				}
			}
			else
			{
				break;
			}
			
		}
		if(!flag)
			cout<<"NO"<<endl;
	}
		
}