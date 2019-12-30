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
	lli p=1;
	while(T--)
	{
		lli N;
		cin>>N;
		string pattern;
		cin>>pattern;
		string text;
		cout<<"Test case #"<<p<<endl;
		p++;
		lli lps[pattern.length()];

		lli j=0;
		lps[0]=0;

		for(lli i=1;i<pattern.length();i++)
		{
			if(pattern[j]==pattern[i])
			{
				lps[i]=j+1;
			//	i++;
				j++;
			}
			else
			{
				while(true)
				{
					if(j==0 || pattern[j]==pattern[i])
					{
						break;
					}
					j=lps[j-1];
				}
				if(pattern[j]==pattern[i])
				{
					lps[i]=j+1;
					j++;
				}
				else
				{
					lps[i]=0;
				//	i++;
				}
			}

			if(lps[i]==0)
				continue;
			lli res=i+1-lps[i];
			if((i+1)%res!=0)
				continue;
			cout<<(i+1)<<" "<<(i+1)/res<<endl;
		}

		cout<<endl;
	}

}