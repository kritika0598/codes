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
		lli n,k,p;
		cin>>n>>k;
		p=k;
		lli Arr[n+1];
		vector<lli> ans;
		lli z=0;
		for(lli i=1;i<=n;i++)
		{
			cin>>Arr[i];
			if(Arr[i]%2!=0)
			{
				z++;
			}
			if(Arr[i]%2!=0 && k>1)
			{
				ans.push_back(i);
				k--;
			}
		}
		if(p==1)
		{
			if(z%2==0)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
				cout<<n<<endl;
			}
			continue;
		}
		if(ans.size()==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		lli o=0;
		for(lli i=ans.back()+1;i<=n;i++)
		{
			if(Arr[i]%2!=0)
			{
				o++;
			}
		}
		ans.push_back(n);
		if(o%2==0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			for(lli i=0;i<ans.size();i++)
			{
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}


	}
}