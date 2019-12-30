#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		lli Arr[26][N+1];
		string s;
		cin>>s;
		memset(Arr,0,sizeof(Arr));
		lli maxi[26];
		lli ans=0;
		memset(maxi,0,sizeof(maxi));
		set<lli> q;
		for(lli i=1;i<=N;i++)
		{
			for(lli j=0;j<26;j++)
    		{
    			Arr[j][i]=Arr[j][i-1];
    		}
    		Arr[s[i-1]-'a'][i]=Arr[s[i-1]-'a'][i-1]+1;
    		q.insert(s[i-1]-'a');
		}
		lli siz=q.size();
		set<lli> :: iterator it;
		for(it=q.begin();it!=q.end();++it)
		{
			lli i=*it;
			lli l=0,r=N;
			maxi[i]=3;
			if(Arr[i][r]==1)
				maxi[i]=3;
			else if(Arr[i][r]==0)
			{
				maxi[i]=0;
			}	
			else if(N<=(2*Arr[i][r]+1))
			{
				maxi[i]=N;
				break;
			}
			else
			{
				lli c[Arr[i][N]+1];
				c[0]=0;
				//cout<<i<<"   ";
				for(lli j=1;j<=Arr[i][N];j++)
				{
					c[j]=lower_bound(Arr[i]+c[j-1],Arr[i]+N,j)-Arr[i];
				//	cout<<c[j]<<" ";
				}
				//cout<<endl;
				for(lli j=Arr[i][N];j>=1;j--)
				{
					for(lli k=1;k<j;k++)
					{
						//cout<<"hello22"<<endl;
						//cout<<(c[j]-c[k]+1)<<" "<<(2*(j-k+1)+1)<<endl;
						if((c[j]-c[k]+1)<=(2*(j-k+1)+1))
						{
							maxi[i]=max(maxi[i],2*(j-k+1)+1);
							//cout<<"hello"<<endl;
						}	
					}
				}
				
			}
			if(maxi[i]>ans)
				ans=maxi[i];
		//	cout<<"maxi "<<i<<" "<<maxi[i]<<endl;
			
		}
		if(ans>N)
			cout<<N<<endl;
		else
			cout<<ans<<endl;
	}
}