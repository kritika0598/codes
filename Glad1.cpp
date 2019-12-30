#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

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
        lli vil[N];
        for(lli i=0;i<N;i++)
        {
            cin>>vil[i];
        }
        lli play[N];
        for(lli i=0;i<N;i++)
        {
            cin>>play[i];
        }
        sort(vil,vil+N);
        sort(play,play+N);
        bool flag=false;
        for(lli i=0;i<N;i++)
        {
            if(play[i]<vil[i])
            {
                cout<<"LOSE"<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<"WIN"<<endl;
        }
    }
}