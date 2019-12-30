#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

void round_nplaces(double &value, const uint32_t &to)
{
    uint32_t places = 1, whole = *(&value);
    for(uint32_t i = 0; i < to; i++) places *= 10;
    value -= whole; //leave decimals
    value *= places;  //0.1234 -> 123.4
    value  = round(value);//123.4 -> 123
    value /= places;  //123 -> .123
    value += whole; //bring the whole value back
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli k,n;
	cin>>n>>k;
	lli Arr[n];
	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
	}

	sort(Arr,Arr+n);

	double ans=(DBL_MAX);
	double l=0;
	double r=k;
	while(l<r)
	{
		double mid=(double)((l+r)/2);
		//cout<<mid<<" "<<l<<" "<<r<<endl;
		double prev=0 , next;
		bool flag=true;
		for(lli i=0;i<n;i++)
		{
			if(Arr[i]==0)
			{
				prev=0;
				next=Arr[i]+mid;
			}
			if(Arr[i]==k)
			{
				prev=Arr[i]-mid;
				if(next<prev)
				{
					flag=false;
						break;
				}
				next=k;
			}
			else
			{
				if(i==0)
				{
					prev=Arr[i]-mid;
					next=Arr[i]+mid;
					if(prev>0)
					{
						flag=false;
						break;
					}
				}
				else if(i==n-1)
				{
					prev=Arr[i]-mid;
					if(next<prev)
					{
						flag=false;
						break;
					}
					next=Arr[i]+mid;
					if(next<l)
					{
						flag=false;
						break;
					}
				}
				else
				{
					prev=Arr[i]-mid;
					if(next<prev)
					{
						flag=false;
						break;
					}
					next=Arr[i]+mid;
				}
				
			}

		}
		//cout<<flag<<endl;
		if(!flag)
		{
			l=mid;
		}
		else
		{
			ans=mid;
			r=mid;
		}
		double l1=l, r1=r;
		round_nplaces(l1,11);
		round_nplaces(r1,11);
		if(l1==r1)
		{
			break;
		}
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}