#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
bool d[1005][1005];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,K;
		cin>>N>>K;
		string s;
		cin>>s;
		lli Arr[N+1];

		memset(d,false,sizeof(d));
		lli prevl, prevr;
		Arr[0]=0;
		for(lli i=1;i<=N;i++)
		{
			Arr[i]=s[i-1]-'0';
			Arr[i]=Arr[i-1]+Arr[i];
		}
		lli l=1;
		lli r=1;
		lli count=0;
		// for(lli i=0;i<=N;i++)
		// {
		// 	cout<<Arr[i]<<" ";
		// }
		// cout<<endl;
		lli idx=0;
		bool flag=false;
		bool foo=false;
		//for(lli i=1;i<=N;i++)
		while(l<=N && r<=N)
		{
			if(Arr[r]-Arr[l-1]==K)
			{
				if(d[l][r])
					count=count;
				else
				{
					count++;
					d[l][r]=true;
				}	

				//idx=l;
				if(Arr[r+1]-Arr[l-1]==K && (r+1<=N))
				{
					if(!flag)
					{
						idx=r;
						r++;
						flag=true;
						//cout<<1<<" "<<l<<" "<<r<<" "<<count<<endl;

					}
					else
					{
						r++;
						//cout<<2<<" "<<l<<" "<<r<<" "<<count<<endl;
					}
					foo=true;
					
				}
				else
				{

					flag=false;
					if(foo)
						r=idx;
					if(l>=r)
						r++;
					else
						l++;
					foo=false;
					//cout<<3<<" "<<l<<" "<<r<<" "<<count<<endl;
				}
				
			}
			else if(Arr[r]-Arr[l-1]>K)
			{
				if(l==r)
				{
					l++;
					r++;
				}
				else
				{
					l++;
				}
				foo=false;
				flag=false;
				//cout<<4<<" "<<l<<" "<<r<<" "<<count<<endl;
			}
			else
			{
			
				r++;
				foo=false;
				flag=false;
				//cout<<5<<" "<<l<<" "<<r<<" "<<count<<endl;
			}
		//	cout<<l<<" "<<r<<" "<<count<<endl;
		}
		cout<<count<<endl;

	}
		
}