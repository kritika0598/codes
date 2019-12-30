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
		lli D;
		cin>>D;
		map<lli,lli>d;
		lli x,y;
		for(lli i=0;i<D;i++)
		{
			cin>>x>>y;
			d[x]=y;
		}
		lli Q;
		cin>>Q;
		while(Q--)
		{
			lli dead;
			cin>>dead;
			lli req;
			cin>>req;
			lli count=0;
			map<lli,lli>:: iterator it;
			for(it=d.begin();it!=d.end();++it)
			{
				if(dead>=it->first)
					count=count+it->second;
			}
			if(count>=req)
			{
				cout<<"Go Camp"<<endl;
			}
			else
			{
				cout<<"Go Sleep"<<endl;
			}

		}
	}
		
}