#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int h1,h2,m1,m2;
	string s1,s2;
	cin>>s1>>s2;
	int pos=s1.find(":");
	string m=s1.substr(pos+1);
	m1=stoi(m);
	string h=s1.substr(0,pos);
	h1=stoi(h);
	pos=s2.find(":");
	m=s2.substr(pos+1);
	h=s2.substr(0,pos);
	m2=stoi(m);
	h2=stoi(h);
	lli m3,h3;
	if((m1+m2)/2>=60)
	{
		m3=((m1+m2)/2)%60;
		h3=(h1+h2+1);
	}
	else
	{
		m3=(m1+m2)/2;
		h3=(h1+h2);
	}

	if(h3%2!=0)
	{
		m3=m3+30;
	}
	if(m3>=60)
	{
		m3=m3%60;
		h3++;
	}
	if(h3/20==0&& m3/10==0)
	{
		cout<<"0"<<h3/2<<":0"<<m3<<endl;
	}
	else if(h3/20==0)
	{
		cout<<"0"<<h3/2<<":"<<m3<<endl;
	}
	else if(m3/10==0)
	{
		cout<<h3/2<<":0"<<m3<<endl;
	}
	else
	{
		cout<<h3/2<<":"<<m3<<endl;
	}
	


}