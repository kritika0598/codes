#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
string s;
lli count=1;
lli cum[100005];
lli N;
lli A=0;
void ans(lli prevSum, lli x, lli y)
{
	lli curSum;
	if(x!=0)
		curSum=cum[y]-cum[x-1];
	else
		curSum=cum[y];
	if(curSum>=prevSum)
	{
		if(y==N-1)
		{
			A++;
		}
		else
		{
			for(lli i=y+1;i<N;i++)
			{
				ans(curSum,y+1,i);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli k=1;
	while(1)
	{
		cin>>s;
		if(s=="bye")
			return 0;
		lli x=s.length();
		lli Arr[x];
		N=x;
		for(lli i=0;i<x;i++)
		{
			Arr[i]=s[i]-'0';
		}
		memset(cum,0,sizeof(cum));
		cum[0]=Arr[0];
		for(lli i=1;i<N;i++)
		{
			cum[i]=cum[i-1]+Arr[i];
		}
		for(lli i=0;i<N;i++)
		{
			ans(0,0,i);
		}

		cout<<k<<". "<<A<<endl;
		A=0;
		k++;
	}
}