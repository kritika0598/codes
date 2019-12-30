#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	string s;
	cin>>s;
	lli ans=0;
	string help="ACTG";

	for(lli i=0;i<4;i++)
	{
		if(s[i]>help[i])
		{
			ans+=min(help[i]-'A'+1+'Z'-s[i], s[i]-help[i]);
		}
		else if(help[i]>s[i])
		{
			cout<<'Z'-help[i]<<endl;
			ans+=min('Z'-help[i]+1+s[i]-'A', help[i]-s[i]);
		}
		cout<<ans<<endl;
	}	
	lli ans1=0;
	for(lli i=N-4,j=0;i<=N-1,j<=3;i++,j++)
	{
		if(s[i]>help[j])
		{
			ans1+=min(help[j]-'A'+1+'Z'-s[i], s[i]-help[j]);
		}
		else if(help[j]>s[i])
		{
			ans1+=min('Z'-help[j]+1+s[i]-'A', help[j]-s[i]);
		}
	}
	//cout<<ans<<" "<<ans1<<endl;
	cout<<min(ans,ans1)<<endl;
}