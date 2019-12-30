#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

vector<string> dict;
lli DP[1005];
lli N;
lli dictionaryContains(string word) 
{ 
    for (int i = 0; i < N; i++) 
        if (dict[i]==word) 
           return true; 
    return false; 
} 

lli ans(string str,lli ind)
{
    lli sz=str.length();
    if(str.length()==0)
    {
        return DP[ind]=1;
    }
    
    if(DP[ind]!=-1)
        return DP[ind];
    
    for(lli i=1;i<=sz;i++)
    {
        if(dictionaryContains(str.substr(0,i)) && 
        ans(str.substr(i,sz-i),i))
        {
            return DP[ind]=1;
        }
    }
    return DP[ind]=0;
    
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
	    dict.clear();
	    cin>>N;
	    string s;
	    for(lli i=0;i<N;i++)
	    {
	        cin>>s;
	        dict.push_back(s);
	    }
	    string str;
	    cin>>str;
	    lli M=str.length();
	    for(lli i=0;i<M;i++)
	    {
	        DP[i]=-1;
	    }
	    
	    if(ans(str,0))
	    {
	        cout<<1<<endl;
	    }
	    else
	    {
	        cout<<0<<endl;
	    }
	}
}