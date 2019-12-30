    #include<bits/stdc++.h>
    #define x first
    #define y second
    using namespace std;
    typedef __int64 ll ;
    const int maxn = 2010, mod = 1000000007;
    pair<int, int> a[maxn];
    int h, w, n;
    ll f[201000], finv[201000],dp[maxn],ans;
    ll power(ll a, int b){
    	ll ans = 1;
    	for (; b; b >>= 1){
    		if (b & 1)ans = ans*a%mod;
    		a = a*a%mod;
    	}
    	return ans;
    }
     
    ll C(int i, int j){
    	return f[i + j] * finv[i] % mod *finv[j] % mod;
    }
    int main()
    {
    	f[0] = finv[0] = 1; 
    	for (int i = 1; i <= 200000; ++i){
    		f[i] = f[i - 1] * i%mod;
    		finv[i] = power(f[i], mod - 2);
    	}
    	scanf("%d%d%d", &h, &w, &n);
    	ans = C(h - 1, w - 1);
    	for (int i = 0; i < n; ++i){
    		scanf("%d%d", &a[i].x, &a[i].y); a[i].x--; a[i].y--;
    	}
    	sort(a, a + n); a[n].x = h - 1; a[n].y = w - 1;
    	for (int i = 0; i <= n; ++i){
    		dp[i] = C(a[i].x, a[i].y);
    		for (int j = 0; j < i; ++j)if (a[j].y <= a[i].y)
    			dp[i] = (dp[i] - dp[j] * C(a[i].x - a[j].x, a[i].y - a[j].y)) % mod;
    	}
    	cout << (dp[n]+mod)%mod << endl;
    	return 0;
    }