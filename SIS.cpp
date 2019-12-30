#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	while(k--)
	{
		lli fa,ta,fb,tb;
		cin>>ta>>fa>>tb>>fb;
		lli cost=0;
		{
			if(fa>b && ta!=tb)
			{
				cost=cost+fa-b;
				fa=b;
			}
			else if(fa<a && ta!=tb)
			{
				cost=cost+a-fa;
				fa=a;
			}
			cost=cost+abs(tb-ta)+abs(fb-fa);
		}
		cout<<cost<<endl;
	}
		
}