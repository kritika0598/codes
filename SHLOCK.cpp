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
		string s;
		cin>>s;
		lli N=s.length();
		lli arr[N+1];
		for(lli i=0;i<N;i++)
		{
			arr[i]=s[i]-'a';
			//cout<<arr[i]<<" ";
		}
		//cout<<endl;
		lli maxi=0;
		for(lli i=0;i<N;i++)
		{
			for(lli j=i+1;j<N;j++)
			{
				if(arr[i]+arr[j]==25)
				{
					if(j-i>maxi)
						maxi=j-i;
				}
			}
		}
		cout<<maxi<<endl;
	}
		
}