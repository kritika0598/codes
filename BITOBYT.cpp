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
	lli N;
	while(T--)
	{
		cin>>N;
		lli cbit=1;
		lli tbit=2;
		lli cnib=0;
		lli tnib=10;
		lli cbyt=0;
		lli tbyt=26;
		for(lli i=1;i<N;i++)
		{
			if(i==tbit)
			{
				cnib=cbit;
				cbit=0;
				tnib=tbit+8;
			}
			if(i==tnib)
			{
				cbyt=cnib;
				cnib=0;
				tbyt=tnib+16;
			}
			if(i==tbyt)
			{
				cbit=2*cbyt;
				cbyt=0;
				tbit=tbyt+2;
			}
		}
		cout<<cbit<<" "<<cnib<<" "<<cbyt<<endl;
	}
		
}