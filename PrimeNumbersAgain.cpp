#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
bool prime[10005];
lli arr[10005];

vector<lli> v;

void sieve()
{
	memset(prime,false,sizeof(prime));
	memset(arr,10000,sizeof(arr));
	//prime[2]=false;
	
	for(lli i=2;i*i<10005;i++)
	{
		if(!prime[i])
		{
			for(lli j=i*i; j<10005;j=j+i)
			{
				prime[j]=true;
			}
		}
	}
	for(lli i=2;i<10005;i++)
	{
		if(!prime[i])
		{
			v.push_back(i);
			arr[i]=1;
		}
	}
	v.push_back(4);
	arr[4]=1;
	v.push_back(27);
	arr[27]=1;
	v.push_back(3125);
	arr[3125]=1;
	v.push_back(823543);
	sort(v.begin(),v.end());
	// for(lli i=0;i<(int)(v.size());i++)
	// {
	// 	cout<<v[i]<<" ";

	// }

}

void digits()
{
	arr[6]=2;
	for(lli i=8;i<10005;i++)
	{
		for(lli j=2;j<i;j++)
		{
			arr[i]=min(arr[i],arr[i-j]+arr[j]);
		}
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	sieve();
	digits();

	while(T--)
	{
		lli N;
		cin>>N;
		cout<<arr[N]<<endl;
	}	
}