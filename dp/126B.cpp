#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string pattern;
	cin>>pattern;
	lli N=pattern.length();
	bool flag=true;
	lli lps[N];
	lli j=0;
	lps[0]=0;

	for(lli i=1;i<pattern.length();)
	{
		if(pattern[j]==pattern[i])
		{
			lps[i]=j+1;
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	// for(lli i=0;i<N;i++)
	// {
	// 	cout<<lps[i]<<" ";
	// }
	// cout<<endl;
	if(lps[N-1]==0)
	{
		cout<<"Just a legend"<<endl;
		return 0;
	}

	for(lli i=1;i<N-1;i++)
	{
		if(lps[i]==lps[N-1])
		{
			string s=pattern.substr(0,lps[N-1]);
			cout<<s<<endl;
			return 0;
		}
		
	}
	lli y=lps[lps[N-1]-1];
	if(y!=0)
	{
		cout<<pattern.substr(0,y)<<endl;
		return 0;
	}
	
	cout<<"Just a legend"<<endl;
		return 0;
}