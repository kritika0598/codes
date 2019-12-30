#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


lli id[200005];

lli root(lli x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(lli x, lli y)
{
    lli p = root(x);
    lli q = root(y);

    if(id[p]!=p && id[q]!=q)
    {
    	if(p>q)
	    	id[p] = id[q];
	    else
	    	id[q]= id[p];
    }
    else if(id[p]!=p && id[q]==q)
    {
    	id[q]=id[p];
    }
    else if(id[q]!=q && id[p]==p)
    {
    	id[p]=id[q];
    }
    else
    {
    	if(p>q)
	    	id[p] = id[q];
	    else
	    	id[q]= id[p];
    }

    
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	lli n,m;
	cin>>n>>m;

	for(lli i=1;i<=n;i++)
	{
		id[i]=i;
	}
	lli a,b;

	vector<lli> v[n+1];

	for(lli i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);

		union1(a,b);
	}
	bool isit[n+1];
	memset(isit,false, sizeof(isit) );
	for(lli i=1;i<=n;i++)
	{
		if(v[i].size()==2)
		{
			isit[i]=true;
		}
	}

	// for(lli i=1;i<=n;i++)
	// {
	// 	cout<<id[i]<<" ";
	// }
	// cout<<endl;

	set<lli> s;
	set<lli> :: iterator it;

	for(lli i=1;i<=n;i++)
	{
		//cout<<root(id[i])<<" ";
		s.insert(root(id[i]));
	}
	//cout<<endl;
	for(lli i=1;i<=n;i++)
	{
		if(!isit[i])
		{
			it = s.find(root(id[i]));
			if(it!=s.end())
				s.erase(it);
		}
	}
	lli c=0;
	cout<<s.size()<<endl;
}