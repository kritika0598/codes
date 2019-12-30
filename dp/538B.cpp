#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
vector<lli> v;

vector<lli> form[1000005];

pair<lli,lli> solve(lli i)
{
	//cout<<"i "<<i<<endl;
	if(i<=0)
		return {INT_MAX,-1};
	if(form[i].size()!=0)
		return {form[i].size(),i};
	lli a=INT_MAX;
	lli ind=0;
	lli val=0;
	vector<lli> ::iterator itr;
	itr=lower_bound(v.begin(),v.end(),i);
	//cout<<*itr<<endl;
	itr--;
//	cout<<"itr "<<*itr<<endl;
//	cout<<i-(*itr)<<endl;
	while(itr!=v.begin())
	{
		
		pair<lli,lli> p=solve(i-(*itr));
		if(p.first<a)
		{
			a=p.first;
			ind=p.second;
			val=*itr;
		}
		itr--;
	}

	for(lli j=0;j<form[ind].size();j++)
	{
		form[i].push_back(form[ind][j]);
	}
	form[i].push_back(val);
	return {form[i].size(),i};
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	v.push_back(0);
	for(lli i=1;i<=1000000;i++)
	{
		lli x=i;
		bool flag=false;
		while(x)
		{
			if(x%10!=0 && x%10!=1)
			{
				flag=true;
				break;
			}
			x=x/10;
		}

		if(!flag)
		{
			v.push_back(i);
		}
	}


	for(lli i=0;i<v.size();i++)
	{
		//cout<<v[i]<<" ";
		form[v[i]].push_back(v[i]);
	}
	//cout<<endl;
	for(lli i=2;i<=9;i++)
	{
		for(lli j=1;j<=i;j++)
		{
			form[i].push_back(1);
		}
	}
	if(form[N].size()!=0)
	{
		cout<<form[N].size()<<endl;
		for(lli i=0;i<form[N].size();i++)
		{
			cout<<form[N][i]<<" ";
		}
		cout<<endl;
		return 0;
	}
	pair<lli,lli> p =solve(N);

	cout<<p.first<<endl;
	for(lli i=0;i<form[N].size();i++)
	{
		cout<<form[N][i]<<" ";
	}
	cout<<endl;
}
