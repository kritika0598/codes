#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[1000005];
lli forw[1000005];
lli backw[1000005];
lli maxi=0;
lli temp[1000005];
map<lli,lli> m;
// vector<pair<lli,lli>> v;
// vector<pair<lli,lli>> :: iterator itr;
// vector<pair<lli,lli>> :: iterator itru;
// vector<pair<lli,lli>> :: iterator itrl;
vector<lli> v;
vector<lli> :: iterator itr;
vector<lli> :: iterator itru;
vector<lli> :: iterator itrd;
lli N;

lli BIT[1000005];

lli get(lli index)
{
	lli ans=0;
	while(index>=1)
	{
		ans=ans+BIT[index];
		index-=index&(-index);
		//cout<<"hello1"<<endl;
	}
//	cout<<"hello1"<<endl;
	return ans;
}

void update(lli index,lli val)
{
//	while(index<=maxi)
	for(lli i=index;i<=maxi;i=i+(i&(-i)))
	{
		//cout<<i<<endl;
		BIT[i]+=val;
		//index+=index&(-index);
		//cout<<"hello1"<<endl;
	}
}




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>N;
	for(lli i=1;i<=N;i++)
	{
		cin>>Arr[i];
		m[Arr[i]]++;
		forw[i]=m[Arr[i]];
	}

	for(lli i=1;i<=N;i++)
	{
		backw[i]=m[Arr[i]]-forw[i]+1;
		temp[i]=backw[i];
		if(backw[i]>maxi)
			maxi=backw[i];
	}
	memset(BIT,0,sizeof(BIT));
	lli ans=0;
	sort(temp,temp+N+1);
	for(lli i=N-1;i>=1;i--)
	{
		if(backw[i+1]!=0)
			update(backw[i+1],1);
		ans=ans+get(forw[i]-1);
		// cout<<backw[i+1]<<" "<<forw[i]<<endl;
		// for(lli j=1;j<=maxi;j++)
		// {
		// 	cout<<BIT[j]<<" ";
		// }
	//	cout<<endl;
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;
	//memset(BIT,0,sizeof(BIT));
	// for(lli i=1;i<=N;i++)
	// {
	// 	v.push_back(backw[i]);
	// }
	// // for(itr=v.begin();itr!=v.end();itr++)
	// // 	{
	// // 		cout<<*itr<<" ";
	// // 	}
	// // 	cout<<endl;

	// sort(v.begin(),v.end());
	// for(itr=v.begin();itr!=v.end();itr++)
	// 	{
	// 		cout<<*itr<<" ";
	// 	}
	// 	cout<<endl;
	//cout<<"hello"<<endl;
	// lli count1=0;
	// backw[N+1]=0;
	// for(lli i=N-1;i>=1;i--)
	// {
	// 	sort(backw+i+1,backw+N+1);
	// 	//cout<<lower_bound(backw+i+1,backw+N+1,forw[i])-(backw+i+1)<<endl;
	// 	count1+=lower_bound(backw+i+1,backw+N+1,forw[i])-(backw+i+1);
	// }

	// cout<<count1<<endl;
		
}