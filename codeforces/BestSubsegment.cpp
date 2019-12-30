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
	double Arr[N+1];
	double Sum[N+1];
	Arr[0]=0;
	Sum[0]=Arr[0];
	double maxi=0;
	lli n=1;
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		if(Arr[i]>maxi)
			maxi=Arr[i];
		Sum[i]=Sum[i-1]+Arr[i];	
	}
	for(lli i=2;i<=N;i++ )
	{
		for(lli j=1;j<=N-i+1;j++)
		{
			if(((Sum[j+i-1]-Sum[j-1])/double(i))>=maxi)
			{
				maxi=((Sum[j+i-1]-Sum[j-1])/double(i));
				n=i;
			}	
		}
	}

	cout<<n<<endl;
}