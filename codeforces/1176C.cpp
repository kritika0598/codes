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
	lli Arr[6]={4,8,15,16,23,42};
	vector<lli> v(N);
	vector<lli> a;
	vector<lli> b,c,d,e,f;
	vector<lli> ::iterator itr;
	for(lli i=0;i<N;i++)
	{
		cin>>v[i];
		if(v[i]==4)
		{
			a.push_back(i);
		}
		if(v[i]==8)
		{
			b.push_back(i);
		}
		if(v[i]==15)
		{
			c.push_back(i);
		}
		if(v[i]==16)
		{
			d.push_back(i);
		}
		if(v[i]==23)
		{
			e.push_back(i);
		}
		if(v[i]==42)
		{
			f.push_back(i);
		}
	}
	lli ans=0;
	lli x,y,z,w,t,u;
	if(N<6)
	{
		cout<<N<<endl;
		return 0;
	}
	while(a.size()!=0)
	{
		if(b.size()!=0 && b[0]<=a[0])
		{
			while(b[0]<=a[0])
			{
				ans++;
				b.erase(b.begin());
				if(b.size()==0)
					break;
			}			
		}
		else
		{
			if(c.size()!=0 && c[0]<=b[0])
			{
				while( c[0]<=b[0])
				{
					ans++;
					c.erase(c.begin());
					if(c.size()==0)
						break;
				}			
			}
			else
			{
				if(d.size()!=0 && d[0]<=c[0])
				{
					while( d[0]<=c[0])
					{
						ans++;
						d.erase(d.begin());
						if(d.size()==0)
							break;
					}			
				}
				else
				{
					if(e.size()!=0 && e[0]<=d[0])
					{
						while(e[0]<=d[0])
						{
							ans++;
							e.erase(e.begin());
							if(e.size()==0)
								break;
						}	
					}
					else
					{
						if(f.size()!=0 && f[0]<=e[0])
						{
							while(f.size()!=0 && f[0]<=e[0])
							{
								ans++;
								f.erase(f.begin());
								if(f.size()==0)
									break;
							}			
						}
						else
						{
							a.erase(a.begin());
							b.erase(b.begin());
							c.erase(c.begin());
							d.erase(d.begin());
							e.erase(e.begin());
							f.erase(f.begin());
						}
					}
				}
			}
		}
	}

	ans+=a.size()+b.size()+c.size()+d.size()+e.size()+f.size();
	cout<<ans<<endl;
}