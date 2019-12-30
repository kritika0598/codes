#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli count_one (lli n)
{
			lli count=0;
            while( n )
            {
            	n = n&(n-1);
               count++;
            }
            return count;
    }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	map<lli,lli> m;
	while(T--)
	{
		lli A,B,C;
		cin>>A>>B>>C;
		lli a=A,b=B,c=C;
		lli temp;
		if(B<A)
		{
			temp=B;
			B=A;
			A=temp;
		}
		lli count=1;
		lli arrC[35];
		lli arrB[35];
		lli arrA[35];
		lli i;
		lli n;
		lli seta=0,setb=0;
		n=A;
		seta=count_one(n);
		n=B;
		setb=count_one(n);
		lli x;
		lli stA,stB;

		while(a!=0 && b!=c)
		{
//			cout<<"hello"<<endl;
			a--;
			b++;
			lli ax=a,bx=b;
			//cout<<a<<" "<<b<<endl;
			stA=0;
			stB=0;
			if(m[a]==0)
				stA=count_one(a);
			else
				stA=m[a];
			if(m[b]==0)
				stB=count_one(b);
			else
				stB=m[b];
			if(stA==seta && stB==setb)
			{
				count++;
				//cout<<count<<endl;
			}	

		}
		//cout<<"hello"<<endl;
		a=A,b=B;
		while(a!=c && b!=0)
		{
			a++;
			b--;
			//cout<<a<<" "<<b<<endl;
			lli ax=a,bx=b;
			stA=0;
			stB=0;
			if(m[a]==0)
				stA=count_one(a);
			else
				stA=m[a];
			if(m[b]==0)
				stB=count_one(b);
			else
				stB=m[b];
			if(stA==seta && stB==setb)
			{
				count++;
				//cout<<count<<endl;
			}
			
			
		}
		cout<<count<<endl;
	}
		
}