#include<bits/stdc++.h>
using namespace std;

int DP[1010][1010];

int foo(int h, int a, int cnt,bool fire)
{
    if( h<=0 || a<=0) return cnt;

    if(DP[h][a] != -1) return DP[h][a];
    if(fire) DP[h][a] = max(DP[h][a], foo(h+3,a+2,cnt+1,!fire));

    return DP[h][a] = max(DP[h][a], max(foo(h-5,a-10,cnt+1,!fire),foo(h-20,a+5,cnt+1,!fire)));
}

int main()
{   int tc;
    cin >> tc;
    int h,a;

    while(tc--){
    bool fire=true;
    memset(DP,-1,sizeof DP);
    cin >> h >> a;

    cout << foo(h,a,-1,fire) << endl;
}
   return 0;

}