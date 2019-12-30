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
	lli L,v,l,r;
	while(T--)
	{
		cin>>L>>v>>l>>r;
		lli k=1;
		lli count=0;
		/*if(l==1 && r==L)
			cout<<0<<endl;
		else
		{
			for(lli i=1 ;i<=L;i++)
			{
				if((i>r || i<l) && (i%v)==0)
				{
					count++;
				}

			}
			cout<<count<<endl;
		}*/
		//if(r==l && )
		cout<<((L/v)-(r/v) + ((l-1)/v))<<endl;
	}
		
}	