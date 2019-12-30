#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	lli arr[n+1];
	lli m[n+5];
	memset(m,0,sizeof(m));
	for(lli i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	lli j;
	for(lli i=1;i<=n;i++)
	{
		m[i]=1;
		j=i;
		while(1)
		{
			m[arr[j]]++;
			//cout<<j<<" "<<arr[j]<<" "<<m[arr[j]]<<endl;
			if(m[arr[j]]>=2)
			{
				//cout<<"hello"<<endl;
				j=arr[j];

				break;
			}
			j=arr[j];

		}
		cout<<j<<" ";
		memset(m,0,sizeof(m));
	}
		
}