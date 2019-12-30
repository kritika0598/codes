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
		string s;
		cin>>s;
		lli Arr[26][N+2];
		memset(Arr,0,sizeof(Arr));
		vector<lli> v[26];
		Arr[s[0]-'a'][0]++;
		v[s[0]-'a'].push_back(0);
		//Arr[s[0]-'a'][N]=0;
		//Arr[s[0]-'a'][N+1]=0;
		lli LIS[26];
		LIS[s[0]-'a']=3;
		memset(LIS,0,sizeof(LIS));
		lli x[26];
		memset(x,0,sizeof(x));
		x[s[0]-'a']=0;
		for(lli i=1;i<N;i++)
		{
			for(lli j=0;j<25;j++)
			{
				Arr[j][i]=Arr[j][i-1];
			}
			Arr[s[i]-'a'][i]=Arr[s[i]-'a'][i-1]+1;
			
			if(Arr[s[i]-'a'][i-1]==0 && Arr[s[i]-'a'][i]==1)
			{
				//Arr[s[i]-'a'][N]=i;
				//Arr[s[i]-'a'][N+1]=i;
				v[s[i]-'a'].push_back(i);
				x[s[i]-'a']=i;
			}	
			lli y=v[s[i]-'a'].size();
			for(lli j=0;j<y;j++)
			{
				if((i-v[s[i]-'a'][j]+1)>(2*(Arr[s[i]-'a'][i])+1))
				{
					v[s[i]-'a'].push_back(i);
					x[s[i]-'a']=i;
					//Arr[s[i]-'a'][N+1]=Arr[s[i]-'a'][N];
					//Arr[s[i]-'a'][N]=i;

				}
			}			


			
			y=v[s[i]-'a'].size();
			for(lli j=0;j<y;j++)
			{
				if((i-v[s[i]-'a'][j]+1)<=(2*(Arr[s[i]-'a'][i])+1))
				{
					x[s[i]-'a']=min(x[s[i]-'a'],v[s[i]-'a'][j]);
				}

				//cout<<i<<" "<<v[s[i]-'a'][j]<<" "<<x[s[i]-'a']<<endl;
			}

			lli z=(2*(Arr[s[i]-'a'][i]-Arr[s[i]-'a'][x[s[i]-'a']]+1)+1);
			LIS[s[i]-'a']=max(LIS[s[i]-'a'],z);
			//cout<<"hello"<<endl;
			//cout<<Arr[s[i]-'a'][i]<<" "<<i<<" "<<Arr[s[i]-'a'][N]<<" "<<x[s[i]-'a']<<" "<<z<<" "<<LIS[s[i]-'a']<<endl;
		}
		{
			lli maxi=3;

			for(lli i=0;i<26;i++)
			{
				if(LIS[i]>maxi)
					maxi=LIS[i];
			}
			if(maxi>N)
				cout<<N<<endl;
			else
				cout<<maxi<<endl;
		}
		
		
	}
		
}