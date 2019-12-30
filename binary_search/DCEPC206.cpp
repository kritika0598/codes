#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli bit[100005];
lli temp[100005];
lli v[1000005];
lli N;

lli get(lli pos)
{
	lli sum=0;
	while(pos>=1)
	{
		sum+=bit[pos];
		pos-=pos&(-pos);
	}
	return sum;
}

void update(lli pos, lli val)
{
	while(pos<=N)
	{
		bit[pos]+=val;
		pos+=(pos&-pos);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		lli Arr[N+1];
		lli sum=0;
		memset(v,0,sizeof(v));
		for(lli i=1;i<=N;i++)
		{
			cin>>Arr[i];
			temp[i]=Arr[i];
			bit[i]=0;

			//sum=sum+Arr[i];
		}

		sort(temp+1,temp+N+1);
		for(lli i=1;i<=N;i++)
		{
			//cout<<v[Arr[i]]<<endl;
			v[Arr[i]]++;
			lli pos=lower_bound(temp+1,temp+1+N,Arr[i])-temp;
			//cout<<get(pos)<<" "<<get(N)<<endl;
			update(pos,Arr[i]);
			//cout<<get(pos)<<" "<<get(N)<<endl;
			//cout<<v[Arr[i]]<<endl;
			sum=sum+get(pos)-Arr[i]*v[Arr[i]];
			//sum=sum+get(pos);
			//cout<<sum<<endl;
		}

		cout<<sum<<endl;

	}
		
}