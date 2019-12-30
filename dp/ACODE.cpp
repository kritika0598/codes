#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli count1=0;
lli DP[5005];
lli DP1[5005];
string s;
lli ans(lli y)
{

	if(y==0)
		return DP1[0]=DP[0];
	else if(y==1)
		return DP1[1]=DP[1];
	if(DP1[y]!=-1)
		return DP1[y];
	if(s[y]=='0')
	{
		return DP1[y]=ans(y-2);
	}
	else if(DP[y]==2)
	{
		return DP1[y]= ans(y-2)+ans(y-1);
	}
	else if(DP[y]==1)
	{
		return DP1[y]= ans(y-1);
	}


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		//string s;
		cin>>s;
		if(s[0]=='0')
			return 0;
		lli N=s.length();
		lli Arr[N];
		for(lli i=0;i<N;i++)
		{
			Arr[i]=s[i]-'0';
		}
		count1=0;
		// for(lli i=N-1;i>=0;i--)
		// {
		// 	if(Arr[i]==0 && Arr[i-1]==0)
		// 	{
		// 		cout<<0<<endl;
		// 		break;
		// 	}
		// 	else if(Arr[i]==0)
		// 	{
		// 		count1=count1+1;
		// 	}
		// 	else if(Arr[i]+10*Arr[i-1]<=27)
		// 	{
		// 		count1=count1+2;
		// 	}
		// 	else
		// 	{
		// 		count1=count1+1;
		// 	}
		// }
		memset(DP,0,sizeof(DP));
		for(lli i=0;i<=N;i++)
		{
			DP1[i]=-1;
		}
		DP[0]=1;
		bool flag =false;
		for(lli y=1;y<N;y++)
		{
			if(Arr[y]==0 && Arr[y-1]==0)
			{
				cout<<0<<endl;
				flag=true;
				break;
			}
			else if(Arr[y]==0 )
			{
				if(Arr[y]+10*Arr[y-1]<=26)
					DP[y]=1;
				else
				{
					cout<<0<<endl;
					flag=true;
					break;
				}
			}
			else if(Arr[y-1]==0)
				DP[y]=1;
			else if(Arr[y]+10*Arr[y-1]<=26)
				DP[y]=2;
			else
				DP[y]=1;
		}

		if(!flag)
		{
			lli x= ans(N-1);
			cout<<x<<endl;
		}
	}
		
}