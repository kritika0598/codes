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
	string s1,s2;
	cin>>s1>>s2;
	lli ans=0;
	lli i=0;
	while(i<n)
	{
		if(s1[i]!=s2[i])
		{
			if(i+1<n && s1[i+1]==s2[i] && s1[i]==s2[i+1])
			{
				ans++;
				i+=2;
			}
			else
			{
				ans++;
				i++;
			}
		}
		else
		i++;
	}
	
	cout<<ans<<endl;
	return 0;
	//cout<<solve(N,s1,s2,0,0)<<endl;	
}