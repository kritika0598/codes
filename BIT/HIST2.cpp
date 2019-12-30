#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli fact(lli N)
{
	if(N==1)
		return 1;
	return N*fact(N-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli N;
		cin>>N;
		if(N==0)
			return 0;
		lli Arr[N];
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}
		sort(Arr,Arr+N);
		lli count=2*N;
		lli Ar1[N];
		for(lli i=0;i<N;i++)
		{
			Ar1[i]=-1;
		}
		lli x;
		if(N%2==0)
		{
			lli k=0;
			lli t=0;
			for(lli i=N-1;i>=0;i=i-4)
			{
				if(i<=0)
					break;
				Ar1[k]=Arr[i];
				Ar1[k+1]=Arr[t];
				Ar1[N-1-k]=Arr[i-1];
				Ar1[N-1-k-1]=Arr[t+1];
				k=k+2;
				t=t+2;
			}

			x=2 *  pow(fact((N/2)),2);
		}
		else
		{
			lli k=0;
			lli t=0;
			for(lli i=N-1;i>=0;i=i-4)
			{
				if(i<=0)
					break;
				Ar1[k]=Arr[i];
				if(Ar1[k+1]==-1)
					Ar1[k+1]=Arr[t];
				Ar1[N-1-k]=Arr[i-1];
				if(Ar1[N-1-k-1]==-1)
					Ar1[N-1-k-1]=Arr[t+1];
				k=k+2;
				t=t+2;
			}
			if(Ar1[k]==-1)
				Ar1[k]=Arr[N/2];
			x=fact((N/2)+1)  * fact(N/2);
		}
		
		for(lli i=0;i<N-1;i++)
		{
			count+=abs(Ar1[i]-Ar1[i+1]);
		//	cout<<Ar1[i]<<" ";
		}
		//cout<<Ar1[N-1]<<endl;
		count=count+Ar1[0]+Ar1[N-1];
		//cout<<endl;
		cout<<count<<" "<<x<<endl;
	}
}