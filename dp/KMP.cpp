#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string text;
	string pattern;

	cin>>text>>pattern;

	lli lps[pattern.length()];

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

	lli i=0;
	j=0;

	while(i<text.length() && j<pattern.length())
	{
		if(text[i]==pattern[j])
		{
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
				i++;
			}
		}
	}

	if(j==pattern.length())
		cout<<"Found"<<endl;
	else
		cout<<"Not found"<<endl;
}