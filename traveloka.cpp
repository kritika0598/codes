#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	stack<lli> st;
	lli x;
	for(lli i=0;i<N;i++)
	{
		cin>>x;
		st.push(x);
	}
	stack<lli> st1;
	for(lli i=0;i<N;i++)
	{
		st1.push(st.top());
		st.pop();
	}
	lli maxi=0;
	while(K-- && !st1.empty())
	{
		{
			maxi=max(maxi,st1.top());
			st1.pop();
		}
	}

	if(st1.empty())
	{
		if(K%2==0)
		{
			cout<<-1<<endl;
		}
		else{
			cout<<maxi<<endl;
		}
	}

}