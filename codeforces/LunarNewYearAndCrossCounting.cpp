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
	string Arr[N][N];
	for(lli i=0;i<N;i++)
	{
		string s;
		cin>>s;
		for(lli j=0;j<N;j++)
		{
			Arr[i][j]=s[j];
		}
	}
	lli count=0;
	for(lli i=1;i<N-1;i++)
	{
		for(lli j=1;j<N-1;j++)
		{
			if(Arr[i][j]=="X" && Arr[i-1][j-1]=="X" && Arr[i-1][j+1]=="X" && Arr[i+1][j+1]=="X" && Arr[i+1][j-1]=="X")
			{
				count++;
			}
		}
		
	}

	cout<<count<<endl;	
}