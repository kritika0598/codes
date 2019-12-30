#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli B;
void reccur(lli a)
{
    cout<<a<<" ";
    if(a==B)
    {
        return ;
    }
    if(a>0)
    {
        reccur(a-5);
    }
    else
    {
        reccur(a+5);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
	    lli N;
	    cin>>N;
	    B=N;
	    cout<<N<<" ";
        reccur(N-5);
	    cout<<endl;
	}
}