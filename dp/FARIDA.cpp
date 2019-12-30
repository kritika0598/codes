#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli Arr[10005];
lli N;
lli DP[10005];
lli foo(lli index)
{
	if(index==N-1)
		return DP[N-1]=Arr[N-1];
	if(DP[index]!=-1)
		return DP[index];
	return DP[index]=max(Arr[index]+foo(index+2), foo(index+1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	lli k=1;
	while(T--)
	{
		lli N;
		cin>>N;
		if(N==0)
		{
			string s, blank;
    		getline(cin, blank); // reads the rest of the line that the number was on
    		getline(cin, blank);
		}
		memset(Arr,0,sizeof(Arr));
		memset(DP,0,sizeof(DP));
		for(lli i=0;i<N;i++)
		{
			DP[i]=-1;
			cin>>Arr[i];
		}

		cout<<"Case "<<k<<": "<<foo(0)<<endl;
		k++;
	}
}