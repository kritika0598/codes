#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	long long H;
	int n;
	cin >> H >> n;
	vector<long long> a(n);
	long long sum = 0;
	long long gap = 0;
	long long h = H;
	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	    sum -= a[i];
	    h += a[i];
	    if (h <= 0) {
	        cout << i + 1 << endl;
	        return 0;
	    }
	    gap = max(gap, sum);
	}
	if (sum <= 0) {
	    cout << -1 << endl;
	    return 0;
	}

	long long whole = (H - gap) / sum;
	H -= whole * sum;
	long long result = whole * n;

	for (int i = 0;; i++) {
	    H += a[i % n];
	    result++;
	    if (H <= 0) {
	        cout << result << endl;
	        break;
	    }
	}
}