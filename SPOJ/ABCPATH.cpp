#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

char Arr[55][55];
lli N,M;
lli DP[55][55];
lli recur(lli i, lli j, char x, lli ans)
{
	lli b=ans;
	if(DP[i][j]!=0)
		return DP[i][j];
//	cout<<x+1<<endl;
	if(i+1<N)
	{
		if(Arr[i+1][j]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i+1,j,x+1,b));
		}
	}
	if(i+1<N && j+1<M)
	{
		if(Arr[i+1][j+1]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i+1,j+1,x+1,b));
		}
	}
	if(j+1<M)
	{
		if(Arr[i][j+1]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i,j+1,x+1,b));
		}
	}
	if(i-1>=0)
	{
		if(Arr[i-1][j]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i-1,j,x+1,b));
		}
	}
	if(i-1>=0 && j-1>=0)
	{
		if(Arr[i-1][j-1]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i-1,j-1,x+1,b));
		}
	}
	if(j-1>=0)
	{
		if(Arr[i][j-1]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i,j-1,x+1,b));
		}
	}
	if(i+1<N && j-1>=0)
	{
		if(Arr[i+1][j-1]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i+1,j-1,x+1,b));
		}
	}
	if(i-1>=0 && j+1<M)
	{
		if(Arr[i-1][j+1]==Arr[i][j]+1)
		{
			ans=max(ans,1+recur(i-1,j+1,x+1,b));
		}
	}

	return DP[i][j]=ans;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//lli N,M;
	lli k=1;
	while(1)
	{
		cin>>N>>M;
		if(N==0 && M==0)
			return 0;
		memset(DP,0,sizeof(DP));
		vector<pair<lli,lli>> v;
		//lli k=0;
		for(lli i=0;i<N;i++)
		{
			for(lli j=0;j<M;j++)
			{
				cin>>Arr[i][j];
				if(Arr[i][j]=='A')
				{
					v.push_back(make_pair(i,j));
				}
			}
		}


		if(v.size()==0)
		{
			cout<<"Case "<<k<<": "<<0<<endl;
			k++;
			//cout<<0<<endl;
		//	return 0;
		}
		else
		{
			lli maxi=1;

			for(lli i=0;i<v.size();i++)
			{
			//	cout<<recur(v[i].first,v[i].second,'A',1)<<endl;
				maxi=max(recur(v[i].first,v[i].second,'A',1),maxi);
			}

			cout<<"Case "<<k<<": "<<maxi<<endl;
			k++;
		}

		
	}
	
}