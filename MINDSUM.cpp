#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2];

ll getSum(ll n) {
    ll sum = 0;
    while(n != 0) {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
    	ll min=9;
    	vector<ll> m[10];
        ll n,d;
        cin >> n >> d;
        ll cnt = 0;
        //ll digits[10];
        //memset(m,-1,sizeof(m));

        while(1) {
            get(n);
            if(m[a[0]] == 0) 
            {
            	if (a[0]<min)
            		min=a[0];
                m[a[0]] = cnt + a[1];
            }
            else 
            {
                break;
            }
            n += d;
            cnt++;
        }

        sort(m.begin(),m.end())


       	vector <ll> :: iterator itr; 
    	for (itr = m.begin(); itr != m.end(); ++itr) 
    	{
    		n=itr->first;
    		n=n+d;
    		ll x=itr->second++;
    		get(n);
    		if(m[a[0]]<x+a[1])
    		{
    			m[a[0]]=x+a[1];
    		}

   		} 


        for(int i=0;i<10;i++) {http://www.techiedelight.com/sort-map-values-cpp/
            if(m[i] != 0) {
                cout << i << " " << m[i] << "\n";
                break;
            }
        }
    }
}