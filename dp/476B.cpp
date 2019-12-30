#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli f[15];

double nCr(lli n, lli r) 
{ 
    return f[n] / (f[r] * f[n - r]); 
} 
  
 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2;
	cin>>s1>>s2;
	lli p1=0,m1=0,q=0,p2=0,m2=0;
	f[0]=1;
	f[1]=1;
	for(lli i=2;i<15;i++)
	{
		f[i]=f[i-1]*i;
	}
	for(lli i=0;i<s1.length();i++)
	{
		if(s1[i]=='+')
		{
			p1++;
		}
		else
		{
			m1++;
		}
	}
	for(lli i=0;i<s2.length();i++)
	{
		if(s2[i]=='+')
		{
			p2++;
		}
		else if(s2[i]=='-')
		{
			m2++;
		}
		else
		{
			q++;
		}
	}

	lli rp,rm;
	rp=p1-p2;
	rm=m1-m2;
	// if(q==0  && rp==0 && rm==0)
	// {
	// 	cout<<fixed<<setprecision(12)<<1<<endl;
	// }
	if(rm<0 || rp<0)
	{
		double z=0;
		cout<<fixed<<setprecision(12)<<z<<endl;
		return 0;
	}
	if(q<rm+rp)
	{
		double z=0;
		cout<<fixed<<setprecision(12)<<z<<endl;
		return 0;
	}
	else
	{
		double ss=pow(2,q);
		double pr=nCr(q,rp);

		double st=(pr/ss);
		cout<<fixed<<setprecision(12)<<st<<endl;
	}

}