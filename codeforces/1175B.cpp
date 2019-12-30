#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli x=pow(2,32);
	x--;
	cout<<x<<endl;
	lli N;
	cin>>N;
	lli ans=0;
	lli mul=1;
	vector<lli> v;
	bool flag=true;
	while(N--)
	{
		string s;
		cin>>s;
		if(s=="add")
		{
			if(flag)
			{
				if(v.size()==0)
				{
					ans++;
				}
				else
				{
					for(lli i=v.size()-1;i>=0;i--)
					{
						mul*=v[i];
						if(ans+mul>=x+1)
						{
							flag=false;
							break;
						}
					}
					ans+=mul;
					mul=1;
				}
			}
			
		}
		else if(s=="for")
		{
			lli a;
			cin>>a;
			if(flag)
			{
				v.push_back(a);
			}
			
		}
		else if(s=="end")
		{
			if(flag)
			{
				// if(mul!=1)
				// {
				// 	mul/=v[size()-1];
				// }
				v.erase(v.end()-1);
			}
			
		}
	}
	if(flag)
		cout<<ans<<endl;
	else
	{
		cout<<"OVERFLOW!!!"<<endl;
	}	
}