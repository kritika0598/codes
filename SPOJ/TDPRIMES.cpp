#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool *prime1;
	prime1=( bool*)malloc(sizeof(  bool)*100000000);
	// bool prime2[10005];

	memset(prime1,false,sizeof(prime1));
	//memset(prime2,false,sizeof(prime2));
	lli k=1;
	for(lli i=2;i*i<100000000;i++)
	{
		//if(i<=1000000)
		{
			if(!prime1[i])
			{
				if(k%100==1)
				{
					cout<<i<<endl;
				}
				for(lli j=i*i;j<100000000;j=j+i)
				{
					// if(j<=1000000)
						prime1[j]=true;
					// else
					// 	prime2[j-1000000]=true;
				}
				k++;
			}
		}	
	}

	for(lli i=10000;i<100000000;i++)
	{
		if(!prime1[i])
		{
			if(k%100==1)
				cout<<i<<endl;
			k++;
		}
	}
}