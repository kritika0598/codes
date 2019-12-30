#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli N1,N2,D;
		cin>>N1>>N2>>D;
		if(N1==0 && N2==0 && D==0)
			return 0;

		vector <lli,lli> child[N2+1];
		vector <lli,lli> parent[N2+1];
		lli x,y;
		for(lli i=0;i<D;i++)
		{
			cin>>x>>y;
			child[y].push_back(x);
			parent[x].push_back(y);
		}

		priority_queue<lli> q;

		for(lli i=1;i<=N2;i++)
		{
			if(parent[i].size()==0)
				q.push(i);
		}


	}
}