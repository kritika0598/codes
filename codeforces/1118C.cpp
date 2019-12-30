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
	lli Arr[N*N];
	map<lli,lli> m;
	map<lli,lli> :: iterator itr;
	for(lli i=0;i<N*N;i++)
	{
		cin>>Arr[i];
		m[Arr[i]]++;
	}

	lli ans[N+1][N+1];

	if(N%2==0)
	{
		for(itr=m.begin();itr!=m.end();itr++)
		{
			if(itr->second%4!=0)
			{
				//cout<<itr->first<<" "<<itr->second<<endl;
				cout<<"NO"<<endl;
				return 0;
			}
		}
		lli x=1,y=1;
		for(lli j=1;j<=N/2;j++)
		{
			for(lli k=1;k<=N/2;k++)
			{
				for(itr=m.begin();itr!=m.end();itr++)
				{
					if(itr->second>=4)
					{
						ans[j][k]=itr->first;
						ans[N-j+1][k]=itr->first;	
						ans[j][N-k+1]=itr->first;
						ans[N-j+1][N-k+1]=itr->first;
						itr->second=itr->second-4;

						break;
					}
					
				}
			}
		}
		
	}
	else
	{
		bool flag=false;
		for(lli j=1;j<=N/2+1;j++)
		{
			for(lli k=1;k<=N/2+1;k++)
			{
				
				if(j!=N/2+1 && k!=N/2+1)
				{
					for(itr=m.begin();itr!=m.end();itr++)
					{
						//cout<<itr->first<<" "<<itr->second<<endl;
						if(itr->second>=4)
						{
							//cout<<j<<" "<<k<<" "<<itr->first<<" "<<itr->second<<endl;
							ans[j][k]=itr->first;
							ans[N-j+1][k]=itr->first;	
							ans[j][N-k+1]=itr->first;
							ans[N-j+1][N-k+1]=itr->first;
							itr->second=itr->second-4;
							flag=true;
							break;
						}
						
					}
					if(!flag)
					{
						cout<<"NO"<<endl;
						return 0;
					}
					flag =false;
				}
				
			}
		}
		for(lli j=1;j<=N/2+1;j++)
		{
			for(lli k=1;k<=N/2+1;k++)
			{
				if(j==N/2+1 && k==N/2+1)
				{
					for(itr=m.begin();itr!=m.end();itr++)
					{
						if(itr->second==1)
						{
							ans[j][k]=itr->first;
							flag=true;
							break;
						}	
						// else
						// {
						// 	cout<<"NO"<<endl;
						// 	return 0;
						// }
					}
					if(!flag)
					{
						cout<<"NO"<<endl;
						return 0;
					}
					flag=false;
				}
				if(k==N/2+1 && j!=N/2+1)
				{
					for(itr=m.begin();itr!=m.end();itr++)
					{
						if(itr->second>=2)
						{
							ans[j][k]=itr->first;
							ans[N-j+1][k]=itr->first;	
							itr->second=itr->second-2;
							flag=true;
							break;
						}
						
					}
					if(!flag)
					{
						cout<<"NO"<<endl;
						return 0;
					}
					flag =false;
				}
				else if(j==N/2+1 && k!=N/2+1)
				{
					for(itr=m.begin();itr!=m.end();itr++)
					{
						if(itr->second>=2)
						{
							ans[j][k]=itr->first;
							ans[j][N-k+1]=itr->first;	
							itr->second=itr->second-2;
							flag=true;
							break;
						}
						
					}
					if(!flag)
					{
						cout<<"NO"<<endl;
						return 0;
					}
					flag = false;
				}
			}
		}

	}
	cout<<"YES"<<endl;
	for(lli i=1;i<=N;i++)
	{
		for(lli j=1;j<=N;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}	
}