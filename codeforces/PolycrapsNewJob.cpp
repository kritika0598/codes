#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	lli min=0, max=0;
	while(t--)
	{
		char T;
		cin>>T;
		lli x,y;
		
		if(T=='+')
		{
			cin>>x>>y;
			if(x<=y)
			{
				if(x>min)
				{
					min=x;
					//cout<<min<<endl;
				}	
				if(y>max)
				{
					max=y;
					//cout<<max<<endl;
				}	
				//cout<<"hey"<<endl;
			}
			else
			{
				if(y>min)
				{
					min=y;
					//cout<<min<<endl;
				}	
				if(x>max)
				{
					max=x;
					//cout<<max<<endl;
				}	
				//cout<<"hey1"<<endl;
			}
		}
		else
		{
			cin>>x>>y;

			//cout<<min<<" "<<max<<endl;
			if(x<=y)
			{
				if(x>=min && y>=max)
				{
					cout<<"YES"<<endl;
				}
				else
				{
					cout<<"NO"<<endl;
				}
			}
			else
			{
				if(y>=min && x>=max)
				{
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
		}
	}
		
}