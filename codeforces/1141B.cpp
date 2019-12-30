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
	lli Arr[N+1];
	cin>>Arr[1];
	lli maxi=0;
	bool flag=false;
	if(Arr[1]==1)
	{
		maxi=1;
		flag=true;
	}	
	lli k=0;
	for(lli i=2;i<=N;i++)
	{
		cin>>Arr[i];
		if(Arr[i]==1 && Arr[i-1]==1)
			k++;
		else if(Arr[i]==1)
			k=1;
		maxi=max(maxi,k);

	}
	lli c=0;
	if(Arr[N]==1 && flag)
	{
		c=2;
		for(lli i=N-1;i>=1;i--)
		{
			if(Arr[i]==1 && Arr[i+1]==1)
			{
				c++;
			}
			else
				break;
		}
		for(lli i=2;i<=N;i++)
		{
			if(Arr[i]==1 && Arr[i-1]==1)
				c++;
			else 
				break;
		}

	}
	cout<<max(c,maxi)<<endl;

}
