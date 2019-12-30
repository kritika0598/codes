#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
set<lli> pd;
lli Arr[1000005];
//int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//lli pd[1000];
	for(lli i=1;i<=8;i++)
	{
		pd.insert(pow(i,i));
	}
	set <lli> :: iterator it;
	// for(it=pd.begin(); it!=pd.end();it++)
	// {
	// 	cout<<*it<<endl;
	// }
	

	lli T;
	memset(Arr,0,sizeof(Arr));
	for(lli i=1;i<1000005;i++)
	{
		lli calc,j=i,ans=0,val;
		if(pd.find(i)!=pd.end())
		{
			Arr[i]=1;
			//cout<<i<<" "<<Arr[i]<<endl;
		}
		
		//cout<<Arr[i]<<endl;
		else
		{
			//cout<<"Hello "<<j<<endl;
			while(j!=0)
			{
				calc=j%10;
				if(calc!=0)
				{
					val=j-(calc*calc);
					if(val>0)
						//Arr[j]=0;
						//continue;
					//else
					{
						//cout<<Arr[val]<<" "<<Arr[i];
						Arr[i]=Arr[i]|Arr[val];
						if(Arr[i])
							break;
					}
				}
				j=j/10;
				//cout<<"hello"<<endl;
			}
		}
		//cout<<Arr[i]<<endl;
	}
	// for(lli i=1;i<15 ; i++)
	// {
	// 	cout<<Arr[i]<<endl;
	// }
	cin>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		//ans=findPanda(N)
		if(Arr[N]!=0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}	
}