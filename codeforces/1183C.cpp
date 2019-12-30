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
		lli k,n,a,b;
		cin>>k>>n>>a>>b;
		if(k%b==0)
		{
			if(k/b<=n)
			{
				cout<<-1<<endl;
				continue;
			}
			if(k%a==0 && k/a>n)
			{
				cout<<n<<endl;
				continue;
			}
			if(k%a!=0 && k/a>=n)
			{
				cout<<n<<endl;
				continue;
			}
			lli p=k/a;
			p--;
			lli q=(k-(p*a))/b;;
			lli g=p*a;
			while(1)
			{
				if(q+p>=n)
				{
					//if((q*b)+(p*a)>=k)
						cout<<p<<endl;
					// else
					// 	cout<<p-1<<endl;
					break;
				}
				else
				{
					p--;
					q=(k-(p*a))/b;
				}

			}
		}
		else
		{
			if(k/b<n)
			{
				cout<<-1<<endl;
				continue;
			}
			if(k%a==0 && k/a>n)
			{
				cout<<n<<endl;
				continue;
			}
			if(k%a!=0 && k/a>=n)
			{
				cout<<n<<endl;
				continue;
			}
			lli p=k/a;
			p--;
			lli q=(k-(p*a))/b;;
			lli g=p*a;
			while(1)
			{
				if(q+p>=n)
				{
					//if((q*b)+(p*a)>=k)
						cout<<p<<endl;
					// else
					// 	cout<<p-1<<endl;
					break;
				}
				else
				{
					p--;
					q=(k-(p*a))/b;
				}

			}
		}
	}
}