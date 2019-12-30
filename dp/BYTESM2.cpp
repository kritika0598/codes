#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[101][101];
lli DP[101][101];
lli w,h;
lli x(lli i,lli j)
{
	if(i>=h || j>=w || j<0)
		return 0;
	if(DP[i][j]!=-1)
		return DP[i][j];
	if(j==0)
		return DP[i][j] = max(x(i+1,j),x(i+1,j+1)) + Arr[i][j];
	else if(j==w-1)
		return DP[i][j] = max(x(i+1,j),x(i+1,j-1)) + Arr[i][j];
	else
		return DP[i][j] = max(x(i+1,j),max(x(i+1,j+1), x(i+1,j-1)))+ Arr[i][j];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		cin>>h>>w;
		memset(Arr,0,sizeof(Arr));
		for(lli i=0;i<101;i++)
		{
			for(lli j=0;j<101;j++)
			{
				DP[i][j]=-1;
			}
		}
		//lli Arr[h][w];
		for(lli i=0;i<h;i++)
		{
			for(lli j=0;j<w;j++)
			{
				cin>>Arr[i][j];
			}
		}
		lli maxi=-1;
		for(lli i=0;i<w;i++)
		{
			maxi=max(x(0,i),maxi);
		}
		cout<<maxi<<endl;
	}
		
}

