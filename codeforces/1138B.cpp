#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	string s1,s2;
	cin>>s1>>s2;

	lli C[N+1];
	lli A[N+1];
	lli k=1,l=1;
	for(lli i=1;i<=N;i++)
	{
		if(s1[i-1]=="1")
		{
			C[k]=i;
			k++;
		}	
		if(s2[i-1]=="1")
		{
			A[l]=i;
			l++;
		}	
	}
}