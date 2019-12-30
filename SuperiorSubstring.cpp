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
		int Arr[27][N+2];
		memset(Arr,0,sizeof(Arr));
		Arr[s[0]-'a'][0]++;
		Arr[s[0]-'a'][N]=0;
		Arr[26][0]=1;
		lli maxi=1;
		for(lli i=1;i<N;i++)
		{
			Arr[26][i]=Arr[0][i];
			for(lli j=0;j<25;j++)
			{
				Arr[j][i]=Arr[j][i-1];
				if(Arr[j][i]>Arr[26][i])
					Arr[26][i]=Arr[j][i];
			}
			Arr[s[i]-'a'][i]=Arr[s[i]-'a'][i-1]+1;
			Arr[s[i]-'a'][N+1]=i;
			if(Arr[s[i]-'a'][i-1]==0 && Arr[s[i]-'a'][i]==1)
				Arr[s[i]-'a'][N]=i;
			if(Arr[s[i]-'a'][i]>Arr[26][i])
					Arr[26][i]=Arr[s[i]-'a'][i];

		}

		lli LIS[N];
		LIS[0]=1;
		for(lli i=1;i<N;i++)
		{

		}






		if(Arr[26][N-1]>=(N/2))
		{
			cout<<N<<endl;
		}
		else
		{
			for(lli i=1;i<N;i++)
			{
				for(lli j=0;j<i;j++)
				{
					for(lli k=0;k<25;k++)
					{
						if(Arr[k][i]-Arr[k][j]>=((i-j)/2))
						{
							if(i-j>maxi)
								maxi=i-j;
						}

						//cout<<i<<" "<<j<<" "<<maxi<<endl;	
					}
				}
			}
			cout<<maxi<<endl;
		}
		// for(lli j=0;j<N;j++)
		// {
		// 	cout<<j<<"------>"<<endl;
		// 	for(lli i=0;i<26;i++)
		// 	{
		// 		cout<<char((i)+'a')<<" "<<Arr[i][j]<<endl;
		// 	}
		// }


		
	}
		
}