#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	string s[2*n-2];
	string s1[2],s2[2];
	lli k=0,l=0;
	for(lli i=0;i<2*n-2;i++)
	{
		cin>>s[i];
		if(s[i].length()==1)
		{
			s1[k]=s[i];
			k++;
		}
		if(s[i].length()==n-1)
		{
			s2[l]=s[i];
			l++;
		}
	}

	if(n==2)
	{
		cout<<"PS"<<endl;
		return 0;
	}

	string s3[8];
	string c;
	s3[0]=s1[0]+s2[0];
	s3[1]=s2[1]+s1[1];
	if(s3[0]==s3[1])
		c=s3[0];
	s3[2]=s1[0]+s2[1];
	s3[3]=s2[0]+s1[1];
	if(s3[2]==s3[3])
		c=s3[2];
	s3[4]=s1[1]+s2[0];
	s3[5]=s2[1]+s1[0];
	if(s3[4]==s3[5])
		c=s3[4];
	s3[6]=s1[1]+s2[1];
	s3[7]=s2[0]+s1[0];
	if(s3[6]==s3[7])
		c=s3[6];
	bool flag=false;
	// for(lli i=0;i<8;i++)
	// {
	// 	cout<<s3[i]<<endl;
	// }
	 cout<<c<<endl;
	map<string,lli> m;
	//flag=false;
	for(lli i=0;i<2*n-2;i++)
	{
		lli z=s[i].length();
		string b=s[i];
		for(lli j=0; j<z;j++)
		{
			if(b[j]!=c[j])
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			if(m[b]==0)
			{
				m[b]=1;
				cout<<"S";
			}
			else if(m[b]==1)
			{
				cout<<"P";
			}
		}
		else
		{
			if(m[b]==0)
			{
				m[b]=2;
				cout<<"P";
			}
			else
			{
				cout<<"S";
			}
			//cout<<"P";
		}
		flag=false;
	}
	return 0;	
}