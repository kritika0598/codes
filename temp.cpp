#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2];
ll a2[2];
queue< pair<ll,ll> > q;

ll getSum(ll n) {
    ll sum = 0;
    while(n != 0) {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

/*void get(ll n,ll cnt,int tag) {
    ll val = 0;
    while((n/10) != 0) {
        val++;
        n = getSum(n);
        // if((n/10) != 0) {
        //     q.push({n,cnt+val});
        // }
    }
    if(tag == 1) {
        //cout << "a updated\n";
        a[0] = n;
        a[1] = val;
    }
    else if(tag == 2){
        //cout << "         a2 updated\n";
        a2[0] = n;
        a2[1] = val;
    }
}
*/

void get(ll n) {
    ll val = 0;
    while((n/10) != 0) {
        val++;
        n = getSum(n);
    }
    a[0] = n;
    a[1] = val;
    //return a;
}

bool msort(pair<ll,ll> a,pair<ll,ll> b) {
    return (a.second < b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n,d;
        cin >> n >> d;
        ll cnt = 0;
        ll digits[10];
        memset(digits,-1,sizeof(digits));
        while(1) 
        {
            //get(n,cnt,1);
            get(n);
            if(digits[a[0]] == -1) {
                digits[a[0]] = cnt + a[1];
            }
            else {
                break;
            }
            n += d;
            cnt++;
        }
        vector< pair<ll,ll> > v;
        for(int i=0;i<10;i++) {
            if(digits[i] != -1) {
                v.push_back({i,digits[i]});
            }
        }
        sort(v.begin(),v.end(),msort);
        for(auto x : v) {
            //cout << "here\n";
            /*ll n2 = x.first;
            ll cnt2 = x.second;
            bool check[10];
            memset(check,false,sizeof(check));
            while(1) {
                get(n2,cnt2,2);
                if(check[a2[0]] == true) {
                    break;
                }
                check[a2[0]] = true;
                if(digits[a2[0]] == -1) {
                    digits[a2[0]] = cnt2 + a2[1];
                }
                else if(digits[a2[0]] > (cnt2+a2[1])) {
                    digits[a2[0]] = cnt2 + a2[1];
                }
                n2 += d;
                cnt2++;
            }*/


            n=x.first;
            n=n+d;
            ll y=x.second++;
            get(n);
            if(digits[a[0]]<y+a[1])
            {
                digits[a[0]]=y+a[1];
            }

        }
        for(int i=0;i<10;i++) {
            if(digits[i] != -1) {
                cout << i << " " << digits[i] << "\n";
                break;
            }
        }
    }
}