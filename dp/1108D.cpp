#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
pair<lli,string> DP[200005][4];
map<char,lli> m;

pair<lli,string> solve(lli N, lli i, char s[], char p,string t,char prev)
{
	if(i==N-1)
		return {0,t+p};
	if(p!=s[i+1])
	{
		return DP[i][m[prev]]=solve(N,i+1,s,s[i+1],t+p,p);
	}
	if(DP[i][m[prev]].first!=-1)
		return DP[i][m[prev]];
	else
	{
		pair<lli,string> X={INT_MAX,""};
		if(p=='B')
		{
			pair<lli,string> z;
			if(prev!='R')
			{
				z=solve(N,i,s,'R',t,prev);
				if(X.first>z.first+1)
				{
					X=z;
					X.first=z.first+1;
				}
			}
			if(prev!='G')
			{
				z=solve(N,i,s,'G',t,prev);
				if(X.first>z.first+1)
				{
					X=z;
					X.first=z.first+1;
				}
			}
			
			z=solve(N,i+1,s,'R',t+'B','B');
			if(X.first>z.first+1)
			{
				X=z;
				X.first=z.first+1;
			}
			z=solve(N,i+1,s,'G',t+'B','B');
			if(X.first>z.first+1)
			{
				X=z;
				X.first=z.first+1;
			}
			return X;
		}
		if(p=='G')
		{
			pair<lli,string> z;
			if(prev!='R')
			{
				z=solve(N,i,s,'R',t,prev);
				if(X.first>z.first+1)
				{
					X=z;
					X.first=z.first+1;
				}
			}
			if(prev!='B')
			{
				z=solve(N,i,s,'B',t,prev);
				if(X.first>z.first+1)
				{
					X=z;
					X.first=z.first+1;
				}
			}
			
			z=solve(N,i+1,s,'R',t+'G','G');
			if(X.first>z.first+1)
			{
				X=z;
				X.first=z.first+1;
			}
			z=solve(N,i+1,s,'B',t+'G','G');
			if(X.first>z.first+1)
			{
				X=z;
				X.first=z.first+1;
			}
			return X;
		}
		if(p=='R')
		{
			pair<lli,string> z;
			if(prev!='B')
			{
				z=solve(N,i,s,'B',t,prev);
				if(X.first>z.first+1)
				{
					X=z;
					X.first=z.first+1;
				}
			}
			if(prev!='G')
			{
				z=solve(N,i,s,'G',t,prev);
				if(X.first>z.first+1)
				{
					X=z;
					X.first=z.first+1;
				}
			}
			
			z=solve(N,i+1,s,'B',t+'R','R');
			if(X.first>z.first+1)
			{
				X=z;
				X.first=z.first+1;
			}
			z=solve(N,i+1,s,'G',t+'R','R');
			if(X.first>z.first+1)
			{
				X=z;
				X.first=z.first+1;
			}
			return X;
		}

	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	char s[N];
	m['R']=1;
	m['G']=2;
	m['B']=3;
	m['?']=0;
	for(lli i=0;i<N;i++)
	{
		cin>>s[i];
	}
	for(lli i=0;i<=N;i++)
	{
		for(lli j=0;j<=3;j++)
			DP[i][j]={-1,""};
	}
	pair<lli,string> z=solve(N,0,s,s[0],"",'?');
	cout<<z.first<<endl;
	cout<<z.second<<endl;			
}