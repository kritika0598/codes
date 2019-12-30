#include<iostream>
#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	string s;
	cin>>s;
	lli count=1;
	lli l=0;
	lli r=N-1;
	lli lcount=1;
	lli rcount=1;
	bool flag =false;
	bool foo1 =false;
	bool foo2 =false;
	//if(!flag)
	{
		while(!foo1)
		{
			if(s[r]==s[r-1])
			{
				rcount=(rcount+1)%MOD;
				r--;
			}
			else if(rcount==N)
				break;
			else
				foo1=true;
		}
		while(!foo2)
		{
			if(s[l]==s[l+1])
			{
				lcount=(lcount+1)%MOD;
				l++;
			}
			else if(lcount==N)
				break;
			else
				foo2=true;
		}
	}
	if(s[0]==s[N-1])
		flag=true;
	//cout<<rcount<<" "<<lcount<<" "<<count<<endl;
	if(lcount==N || rcount==N)
	{
		count=N;
		for(lli i=1;i<=N;i++)
		{
			count=(count+N-i)%MOD;
			//cout<<count<<" ";
		}
		//cout<<endl;
	}
	else
	{
		count=(count+rcount+lcount)%MOD;
	
		if(flag)
		{
			count=(count+rcount-1+lcount-1+1+((lcount-1)*(rcount-1))%MOD)%MOD;
		}
	}
	

	cout<<count%MOD<<endl;
		
}