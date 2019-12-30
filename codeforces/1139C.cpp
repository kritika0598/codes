#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli ID[1000005];
lli M=1000000007;
lli pow_mod(lli base,lli exponent)
{
	if(base == 1)
	return 1;
	lli x =1 ,y = base;
	while(exponent>0)
	{
		if(exponent%2)
		{
			x = (x*y)%M;
		}
		y = (y*y)%M;
		exponent = exponent>>1;
	}
	return x;
}

lli root(lli x)
{
	while(ID[x]!=x)
	{
		ID[x]=ID[ID[x]];
		x=ID[x];
	}
	return x;
}

void union1(lli x,lli y)
{
	lli p=root(x);
	lli q=root(y);
	if(p>q)
	{
		ID[p]=ID[q];
	}
	else
	{
		ID[q]=ID[p];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	bool Val[N+1];
	memset(Val,false,sizeof(Val));
	lli x,y,z;
	memset(ID,0,sizeof(ID));
	bool flag=true;
	lli cnt=0;
	for(lli i=1;i<=N;i++)
	{
		ID[i]=i;
	}
	for(lli i=0;i<N-1;i++)
	{
		cin>>x>>y>>z;

		if(z!=1)
		{
			union1(x,y);
			Val[x]=true;
			Val[y]=true;
		}
		else
		{
			cnt++;
			flag=false;
		}
	}
	if(flag)
	{
		cout<<0<<endl;
		return 0;
	}
	lli ans=pow_mod(N,K)%M;
	//cout<<ans<<endl;
	if(cnt==N-1)
	{
		cout<<((ans%M)-N)%M<<endl;
		return 0;
	}
	for(lli i=1;i<=N;i++)
	{
		x=i;
		while(ID[x]!=x)
		{
			ID[x]=ID[ID[x]];
			x=ID[x];	
		}		
	}
	map<lli,lli> m;
	map<lli,lli> :: iterator itr;
	for(lli i=1;i<=N;i++)
	{
		m[ID[i]]++;
	}
	for(itr=m.begin();itr!=m.end();itr++)
	{
	//	cout<<itr->first<<" "<<itr->second<<endl;
		if(Val[itr->first])
			ans=(ans-(pow_mod((itr->second),K))%M)%M;
	}
	for(lli i=1;i<=N;i++)
	{
		if(Val[i]==false)
			ans--;
	}
	ans=(ans+M)%M;
	cout<<ans%M<<endl;

}