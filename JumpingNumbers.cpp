#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> s;
void bfs(lli N, lli num)
{
    queue<lli> q;
    q.push(num);
    while(!q.empty())
    {
        num=q.front();
        q.pop();
        if(num<=N)
        {
            s.push_back(num);
            lli last_digit=num%10;
            if(last_digit==0)
            {
                q.push((num*10) + last_digit+1);
            }
            else if(last_digit==9)
            {
                q.push((num*10) + last_digit-1);
            }
            else
            {
                q.push((num*10) + last_digit-1);
                q.push((num*10) + last_digit+1);
            }
        }
    }
}



int main() 
{
    lli T;
    cin>>T;
    while(T--)
    {
        lli N;
        cin>>N;
        s.push_back(0);
        for(lli i=1;i<=N && i<=9 ;i++)
        {
            bfs(N,i);
        }
        sort(s.begin(),s.end());
        for(lli i=0;i<s.size();i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
        s.clear();
    }
	//code
	return 0;
}