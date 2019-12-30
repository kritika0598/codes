#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,c,s;
	lli coins=1000;
	cin>>N>>c;
	bool flag=true;
	double l=0;
	double r=N;
	lli prev, prevval;
	//lli k=5;
	
	//lli y=ceil((l+r)/k);
	lli z;
	if(N<=1000)
		z=15;
	else if(N<=2000)
		z=20;
	else if(N<=5000)
		z=40;
	else if(N<=8000)
		z=60;
	else if(N<=15000)
		z=70;
	else
		z=80;
	//lli z=85;
	lli y=ceil((l+r)/z);
	lli x=y;
	while(flag && coins>=0)
	{
		//y=y/2;
		if(y==0)
			y=1;
		cout<<1<<" "<<y<<endl;
	//	prev=y;
		coins--;
		//x=y-1;
		//cout<<coins<<endl;
		cin>>s;
	//	prevval=s;
		if(s==1)
		{

			if(y==1 || y==0)
			{
				x=1;
				flag=false;
			}
			r=y;
			cout<<2<<endl;
			coins=coins-c;
			//cout<<coins<<endl;
			if(r-l<z)
			{
				if(z<=30)
				{
					y=(l+r)/(2);
					z=2;
				}
				// else if(z<=20)
				// {
				// 	y=(l+r)/(2);
				// 	z=10;
				// }
				// else if(z<=30)
				// {
				// 	y=(l+r)/(2);
				// 	z=20;
				// }
				else if(z<=40)
				{
					z=10;
					y=l+(l+r)/(z);
					
				}
				else if(z<=50)
				{
					z=20;
					y=l+(l+r)/(z);
				}
				else if(z<=70)
				{
					z=30;
					y=l+(l+r)/(z);
				}
				// else if(z<=70)
				// {
				// 	y=(l+r)/(2);
				// 	z=60;
				// }
				// else if(z<=80)
				// {
				// 	y=(l+r)/(2);
				// 	z=70;
				// }
				else 
				{
					z=40;
					y=l+(l+r)/z;
					
				}
				if(l==r)
				{
					flag=false;
					x=y;
				}
			}
			else
			{
				if(ceil((l+r)/z)==(r-l))
					y=l+(ceil((l+r)/(2*z)));
				else
					y=l+ceil((l+r)/z);
				if(y>r || y<l)
				{
					
					y=(l+r)/(2);
				}
			}
			//cout<<" coins "<< coins<<endl;
//			cout<<l<<" "<<r<<endl;

			//if(l==r)
		}
		else if(s==0)
		{
			l=y+1;
			//y=ceil((l+r)/2);
			if(ceil((l+r)/z)==(r-l))
				y=l+(ceil((l+r)/(2*z)));
			else
				y=l+ceil((l+r)/z);
			if(y>r || y<l)
			{
				y=(l+r)/(2);
			}
			if(r-l<z)
			{
				
				if(z<=30)
				{
					y=(l+r)/(2);
					z=2;
				}
				// else if(z<=20)
				// {
				// 	y=(l+r)/(2);
				// 	z=10;
				// }
				// else if(z<=30)
				// {
				// 	y=(l+r)/(2);
				// 	z=20;
				// }
				else if(z<=40)
				{
					z=10;
					y=l+(l+r)/(z);
					
				}
				else if(z<=50)
				{
					z=20;
					y=l+(l+r)/(z);
				}
				else if(z<=70)
				{
					z=30;
					y=l+(l+r)/(z);
				}
				// else if(z<=70)
				// {
				// 	y=(l+r)/(2);
				// 	z=60;
				// }
				// else if(z<=80)
				// {
				// 	y=(l+r)/(2);
				// 	z=70;
				// }
				else 
				{
					z=40;
					y=l+(l+r)/z;
					
				}
				if(y==1 || y==0)
				{
					x=1;
					flag=false;
				}
			}	
			//cout<<" coins "<< coins<<endl;
//			cout<<l<<" "<<r<<endl;

		}
		else
		{
			continue;
		}

		
	}

	cout<<3<<" "<<x<<endl;
	

		
}