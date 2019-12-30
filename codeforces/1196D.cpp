#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--)
	{
		lli n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		string a="",b="",c="";
		lli len=0;
		for(lli i=0;i<k/3;i++)
		{
			a=a+"RGB";
			b=b+"GBR";
			c=c+"BRG";
			len=len+3;
		}

		if(len<k)
		{
			lli x=k-len;
			if(x==1)
			{
				a=a+"R";
				b=b+"G";
				c=c+"B";
			}
			else if(x==2)
			{
				a=a+"RG";
				b=b+"GB";
				c=c+"BR";
			}
		}

		lli ans=k;
		for(lli i=0;i<=n-k;i++)
		{
			lli p=0,q=0,r=0;
			for(lli j=0;j<k;j++)
			{
				if(a[j]!=s[i+j])
				{
					p++;
				}
				if(b[j]!=s[i+j])
				{
					q++;
				}
				if(c[j]!=s[i+j])
				{
					r++;
				}
			}
			ans=min(ans,min(p,min(q,r)));
		}

		cout<<ans<<endl;

	}		
}