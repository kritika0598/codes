#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N, k;
	cin>>N>>k;
	lli a[N+1];
	lli b[N+1];
	lli ind[N+1];
	lli ans[N+1];
	vector<lli> v;
	for(lli i=0;i<N;i++)
	{
		lli x;
		cin>>x;
		a[i]=x;
		b[i]=x;
		ind[x]=i;
		v.push_back(x);
	}
	lli cn=1;
	lli Ans[N+1];
	memset(Ans,0,sizeof(Ans));
	sort(b,b+N);
	for(lli i=N-1;i>=0;i--)
	{
		lli c=b[i];
		if(Ans[ind[b[i]]]!=0)
			continue;
		lli f=find(v.begin(),v.end(),c)-v.begin();
		lli q=v.size();

		lli st=max(0,f-k); lli en=min(q-1,f+k);
		for(lli j=st;j<=en;j++)
		{
			Ans[ind[v[j]]]=cn;
		}
		v.erase(v.begin()+st, v.begin()+en+1);
		if(cn==1)
			cn=2;
		else
			cn=1;
	}

	for(lli i=0;i<=N-1;i++)
	{
		cout<<Ans[i];
	}
	cout<<endl;

}