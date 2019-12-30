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

		lli seta,setb,set1a,set1b,i,x,y,count=0 ;

		seta = count_one(A) ;
		setb = count_one(B) ;

		for(i=0;i<=C;i++){

			x = i ;
			y = C-i ;

			set1a = count_one(x) ;
			set1b = count_one(y) ;

			if(seta==set1a && setb==set1b)
				count++;

			//if(seta==set1b && setb==set1a)
				//count++;


		}
		cout<<count<<endl;
	}
}