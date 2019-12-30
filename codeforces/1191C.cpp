#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,k;
	cin>>n>>m>>k;

	lli Arr[m];
	for(lli i=0;i<m;i++)
	{
		cin>>Arr[i];
	}

	lli div=n/k;

	if(n%k!=0)
		div++;

	lli place1[m];
	lli place2[m];
	lli ans=0;
	for(lli i=0;i<m;i++)
	{
		place1[i]=(Arr[i]/k);
		if(Arr[i]%k==0)
		{
			place1[i]--;
			place2[i]=k-1;
		}
		else
			place2[i]=(Arr[i]%k)-1;
	}

	lli p=place1[0];
	for(lli i=0;i<m;)
	{
		while(place1[i]==p)
		{
			i++;
		}
		ans++;
		for(lli j=i;j<m;j++)
		{
			place2[j]=place2[j]-i;
			if(place2[j]<0)
			{
				place1[j]--;
			}
		}
		p=place1[i];
			
	}
	cout<<ans<<endl;
}

