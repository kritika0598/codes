#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<vector<int>> ans;
lli DP[100005];
lli job(int n,int id[],int d[],lli m[],vector<int> x;)
{
if(n==0)
{
	ans.push_back(x);
	return 0;
}
if(DP[n]!=-1)
	return DP[n];
vector<int> temp=x;
temp.push_back(n-1) //index push kara
if(n>d[n-1])
return  DP[n]=job(n-1,id,d,m,x);
else
return DP[n]=max((m[n-1] + job(n-1,id,d,m,temp)),job(n-1,id,d,m,x));
}
int main()
{
int n,i;
cin>>n;
int id[n],d[n];
lli m[n];
for(i=0;i<n;i++)
{
cin>>id[i]>>d[i]>>m[i];
}
vector<int> x;
memset(DP,-1,sieof(DP));
cout<<job(n,id,d,m,x)<<endl;
return 0;
}