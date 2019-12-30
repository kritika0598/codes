#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	lli T;
	//cin>>T;
	scanf("%lld",&T);
	while(T--)
	{
		lli N,C;
		//cin>>N>>C;
		scanf("%lld %lld",&N, &C);
		lli Arr[N];
		scanf("%lld",&Arr[0]);
		for(lli i=1;i<N;i++)
		{
			scanf("%lld",&Arr[i]);
		}
		sort(Arr,Arr+N);
		lli low=0;
		lli hi=(Arr[N-1]-Arr[0]);

		while(low<hi)
		{
			lli mid=low+(-low+hi+1)/2;
			lli cowsplaced=1;
			lli lastpos=Arr[0];

			for(lli i=1;i<N;i++)
			{
				if(Arr[i]-lastpos>=mid)
				{
					cowsplaced++;
					lastpos=Arr[i];
				}
			}
			if(cowsplaced>=C)
				low=mid;
			else
				hi=mid-1;
		}

	//	cout<<hi<<endl;
		printf("%lld\n",hi);

	}
	return 0;
		
}