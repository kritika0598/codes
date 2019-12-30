#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
set<lli> v;
set<lli> :: iterator itr;
lli N;
void solve(lli cur, lli sum,lli len)
{
	if(sum>10)
		return;
	if(len>10)
		return ;
	if(sum==10 )
	{
		v.insert(cur);
		if(v.size()==N)
		{
			itr=v.end();
			itr--;
			cout<<*(itr)<<endl;
			exit(0);
		}
	}

	for(lli i=0;i<10;i++)
	{
		solve(cur*10+i,sum+i,len+1);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	solve(0,0,0);
}