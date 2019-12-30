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
	while(N--)
	{
		lli l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;

		lli x,y;
		x=l1;
		y=r2;

		if(x==y)
		{
			if(x+1<=r1)
				x++;
			else if(y-1>=l2)
				y--;
		}

		cout<<x<<" "<<y<<endl;
	}
}