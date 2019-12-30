#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

void prin(vector<lli> ans)
{
	for(lli i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
}

lli su(vector<lli> ans)
{
	lli sum=0;
	for(lli i=0;i<ans.size();i++)
	{
		sum+=ans[i];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli sumc=0;
	vector<lli> c;
	vector<lli> ans;
	lli p=0,n=0;
	vector<double> v;
	bool flag[N];
	memset(flag,false,sizeof(flag));
	double z;
	for(lli i=0;i<N;i++)
	{
		cin>>z;
		double x=z;
		if((lli)x==z)
		{
			flag[i]=true;
			c.push_back(ceil(z));
			sumc+=x;
		}
		else
		{
			c.push_back(ceil(z));
			sumc+=(ceil(z));
		}
	}

	if(sumc==0)
	{
		ans=c;
		prin(ans);
		return 0;
	}
	else
	{
		lli difc=sumc;

		if(difc>0)
		{
				for(lli i=0;i<c.size();i++)
				{
					ans.push_back(c[i]);
					if(difc!=0 && flag[i]==false)
					{
						difc--;
						ans[i]--;
					}
					cout<<ans[i]<<endl;
				}
		}


	}




}