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
	lli z[1000005];
	z[1]=1;
	z[0]=0;
	for(lli i=2;i<=1000000;i++)
	{
		z[i]=z[i-1]+i;
	}
	while(T--)
	{
		lli N,K;
		cin>>N>>K;
		string s;
		lli Arr[N+1];
		map<lli,lli>m;
		map<lli,lli> :: iterator itup, itlow, it;
		cin>>s;
		if(K>N)
		{
			cout<<0<<endl;
			continue;
		}
		//Arr[0]=0;
		Arr[0]=s[0]-'0';
		m[Arr[0]]++;
		for(lli i=1;i<N;i++)
		{
			//cin>>Arr[i];
			Arr[i]=(s[i]-'0')+Arr[i-1];
			m[Arr[i]]++;
		}
		// for(lli i=0;i<N;i++)
		// {
		// 	cout<<Arr[i]<<" ";
		// }

		// cout<<endl;
		// for(it=m.begin();it!=m.end();++it)
		// {
		// 	cout<<it->first<<" "<<it->second<<endl;
		// }

		lli count=0;

		if(K==0){
			for(it=m.begin();it!=m.end();++it)
			{
				if(it->first==0)
				{
					count=count+z[it->second];
					//count=count+it->second;
				}
				else
				{
					count=count+z[it->second-1];
				//	count=count+it->second-1;
				}	
			}
			cout<<count<<endl;
			continue;
		}
		bool flag=false;
		if(m[0]==0)
		{
			m[0]=1;
			flag=true;
		}
		for(it=m.begin();it!=m.end();++it)
		{
			lli x=it->first + K;
			itlow=m.lower_bound(x);
			//cout<<"hello"<<x<<" "<<itlow->first<<endl;
			itup=m.upper_bound(x);
			//cout<<"hello"<<x<<" "<<itlow->first<<" "<<itup->first<<endl;
			if(itlow->first!=itup->first || (itlow->first==itup->first && itlow->first ==x && x<=Arr[N-1]) )
			{
				//cout<<"hello"<<x<<" "<<itlow->first<<endl;
				if(it->first==0)
				{
					count=count+(itlow->second)*(it->second)+itlow->second;
					if(flag)
						count=count/2;
				}
				else if(it->second ==1)
				{
					count=count+(itlow->second);
				}
				else
				{
					count=count+((it->second)-1)*(itlow->second)+itlow->second;
				}
				//cout<<count<<endl;
			}

		}
		// if(flag)
		// 	cout<<count/2<<endl;
		// else
			cout<<count<<endl;
	}

		
}