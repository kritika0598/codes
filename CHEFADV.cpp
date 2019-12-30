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
		lli N,M,X,Y;
		cin>>N>>M>>X>>Y;
		lli a=1;
		lli b=1;
		lli x,y;
		N=N-1;
		M=M-1;
	
		x=(N/X);
		y=(M/Y);
		a=(x*X);
		b=(y*Y);
		if(((N-a)==0 && (M-b)==0) || ((N-a-1)==0 &&(M-b-1)==0))
			cout<<"Chefirnemo"<<endl;
		else
			cout<<"Pofik"<<endl;
		
	}
		
}