#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long int lli;

set<lli> s;
set<lli> :: iterator it,r8,l8,temp;
lli m,n;
lli ans = 0;

vector<pair<lli,lli> > mp[1000005];

void solve(lli x) {
    it = s.find(x);
    if(it == s.begin()) 
    {
        r8 = it;
        r8++;
        lli ri = *r8;
        lli fi = mp[ri][0].first;
        lli se = mp[ri][0].second;
        ans -= fi;
        ans += (1 + ri-1);
        ans += (x+1);
        mp[ri].erase(mp[ri].begin());
        mp[ri].push_back({x+1,se});
      //  mp[x].erase(mp[x].begin());
        mp[x].push_back({1,ri-1});
        return;
    }
    temp = it;
    if((++temp) == s.end()) {
        l8 = it;
        l8--;
        lli le = *l8; 
        lli fi = mp[le][0].first;
        lli se = mp[le][0].second;
        ans -= se;
        ans += (le+1 + n);  
        ans += (x-1);
     //   mp[x].erase(mp[x].begin());
        mp[le].erase(mp[le].begin());
        mp[x].push_back({le+1,n});
        mp[le].push_back({fi,x-1});
        return;
    }
    l8 = it;
    r8 = it;
    l8--;
    r8++;
    int ri = *r8;
    int le = *l8;
    lli fi1 = mp[le][0].first;
    lli se1 = mp[le][0].second;
    lli fi2 = mp[ri][0].first;
    lli se2 = mp[ri][0].second;
    ans -= (fi2 + se1);
    ans += (le+1 + ri-1);
    ans += (x-1 + x+1);
 //   mp[x].erase(mp[x].begin());
    mp[le].erase(mp[le].begin());
    mp[ri].erase(mp[ri].begin());
    mp[le].push_back({fi1,x-1});
    mp[ri].push_back({x+1,se2});
    mp[x].push_back({le+1,ri-1});
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    lli x;
    for(int i=0;i<m;i++) {
        cin >> x;
        if(i == 0) {
            ans = 1+n;
            cout << ans <<endl;
            s.insert(x);
            mp[x].push_back({1,n});
            continue;
        }
        if(s.find(x)!=s.end())
        {
        	cout<<ans<<endl;
        	continue;
        }
        s.insert(x);
        solve(x);
        cout << ans << endl;
    }
}