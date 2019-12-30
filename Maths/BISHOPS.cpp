#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string N;
	while(cin>>N)
	{
		//cin>>N;
		if(!(N[0]>='0' && N[0]<='9'))
			break;
		vector<lli> v,ans;
		if(N=="1")
			cout<<1<<endl;
		else
		{
			for(lli i=N.size()-1;i>=0;i--)
			{
				v.push_back(N[i]-'0');
			}
			lli rem=0;

			lli b;
			for(lli i=0;i<N.size();i++)
			{
				b=v[i]*2+rem;
				rem=b/10;
				b=b%10;
				ans.push_back(b);
			}
			if(rem!=0)
				ans.push_back(rem);

			ans[0]=ans[0]-2;
			if(ans[0]<0)
			{
				ans[0]=ans[0]+10;
				lli i=1;
				while(ans[i]==0)
				{
					ans[i]=9;
					i++;
				}
				ans[i]--;
			}

			if(ans[ans.size()-1]==0)
				ans.pop_back();
			for(lli i=ans.size()-1;i>=0;i--)
			{
				cout<<ans[i];
			}
			cout<<endl;
		}	
	}
}