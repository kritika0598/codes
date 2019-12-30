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
		bool flag=false;
		if(Arr[0]==1)
		{
			flag=true;
			cout<<Arr[0]<<" ";
		}
		if(flag && N==3 && Arr[1]==2 && Arr[2]==3)
		{

			//if(Arr[1]==2 && Arr[2]==3)
			{
				cout<<2<<" "<<3<<" ";
			}
		}
		else if(N==2 && Arr[0]==2 && Arr[1]==3)
		{
			//if(Arr[0]==2 && Arr[1]==3)
			{
				cout<<2<<" "<<3<<" ";
			}
		}
		else
		{
			for(lli i=N-1;i>=0;i--)
			{
				cout<<Arr[i]<<" ";
				if(flag && i==1)
					break;

			}

		}
		
		cout<<endl;
	}	
}