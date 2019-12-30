#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Tree[1000005];
lli N;

void update1(lli x,lli val)
{
	for(lli i=x;i<=N;i+=(i&-i))
	{
		Tree[i]+=val;
	}
}

lli query1(lli x)
{
	lli sum=0;
	for(lli i=x;i>0;i-=(i&-i))
	{
		sum=sum+Tree[i];
	}
	return sum;

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(Tree,0,sizeof(Tree));
	cin>>N;
	lli Q;
	cin>>Q;
	string type;
	lli x,y;
	while(Q--)
	{
		cin>>type;
		cin>>x>>y;
		if(type=="add")
		{
			update1(x,y);
			//cout<<query1(x)<<endl;
		}
		else
		{
			cout<<query1(y)-query1(x-1)<<endl;
		}
	}
		
}