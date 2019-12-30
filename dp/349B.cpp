#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool cmp(lli a, lli b)
{
	return a>b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// lli T;
	// cin>>T;
	// while(T--)
	{
	   // ;
	    lli W;
	    cin>>W;
	    vector<pair<lli,lli>> b;
	    lli weight[10];
	    for(lli i=1;i<=9;i++)
	    {
	        cin>>weight[i];
	        b.push_back({weight[i],i});
	    }
	    sort(b.begin(),b.end());
	    lli ndigit=W/b[0].first;
	    if(W<b[0].first)
	    {
	    	cout<<-1<<endl;
	    	return 0;
	    }

	    for(lli j=1,i=9;j<=ndigit && i>0;)
	    {
	    	if(W-weight[i]>=(b[0].first*(ndigit-j)))
	    	{
	    		W-=weight[i];
	    		cout<<i;
	    		j++;
	    	}
	    	else
	    	{
	    		i--;
	    	}
	    }
	}
}