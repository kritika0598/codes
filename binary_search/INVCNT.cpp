#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
//lli Arr[200005];
lli temp[200005];
lli bit[200005];
lli N;

lli get(lli idx)
{
	lli sum=0;
	while(idx>=1)
	{
		sum=sum+bit[idx];
		idx-=idx&(-idx);
	}
	return sum;
}

void update(lli idx,lli val)
{
	while(idx<=N)
	{
		bit[idx]+=val;
		idx+=idx&(-idx);
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
		//lli N;
		cin>>N;
		lli Arr[N+1];
		for(lli i=1;i<=N;i++)
		{
			cin>>Arr[i];
			temp[i]=Arr[i];
			bit[i]=0;
		}
		sort(temp+1,temp+1+N);
		lli sum=0;
		for(lli i=1;i<=N;i++)
		{
			lli pos=lower_bound(temp+1,temp+1+N,Arr[i])-(temp);
			//cout<<pos<<endl;
			sum=sum+get(N)-get(pos);
			update(pos,1);
		}

		cout<<sum<<endl;
	}
		
}