#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	lli Arr[N];
	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}
	lli maximum_ending_here=0;
	lli maximum_so_far=0;
	lli start=0;
	lli end=0;
	for(lli i=0;i<N;i++)
	{
		if(maximum_ending_here<=M)
		{
			//end=i;
			if(maximum_so_far<maximum_ending_here)
			{
				maximum_so_far=maximum_ending_here;
			}
		}
		maximum_ending_here=maximum_ending_here+ Arr[i];
		if(maximum_ending_here==M)
		{
			maximum_so_far=maximum_ending_here;
			break;
		}
		else
		{
			while(maximum_ending_here>M)
			{
				maximum_ending_here=maximum_ending_here-Arr[start];
				if(maximum_ending_here==M)
				{
					maximum_so_far=maximum_ending_here;
					break;
				}
					start++;
				
			}
			
		}
		

	}
	cout<<maximum_so_far<<endl;
		
}