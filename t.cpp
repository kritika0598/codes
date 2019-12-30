#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		int flag = 0;
		int pos = -1;
		int maxi = INT_MIN;
		for(int i=0;i<n;i++) {
			cin >> a[i];
			if(a[i] > maxi) {
				maxi = a[i];
				pos = i;
			}
		}
		if(maxi == -1) {
			cout << "inf\n";
			continue;
		}
		int k = pos+1;
		int ans = maxi;
		while(k<n && a[k] == -1) {
			k++;
			ans++;
		}
		if(k == n) {
			// go to pre check and lenth infinite
			int flag3 = 0;
			int q = pos;
			int v = a[pos];
			while(q > 0) {
				q--;
				if(v > 1) {
					v--;
				}
				else {
					v = maxi;
				}
				if(v == a[q]) {
					continue;
				}
				if(a[q] == -1) {
					//q--;
					continue;
				}
				flag3 = 1;
				break;
			} 
			if(flag3) {
				cout << "impossible\n";
				continue;
			}
			cout << "inf\n";
			continue;
		}
		ans -= (a[k]-1);
		if(ans < maxi) {
			cout << "impossible\n";
			continue;
		}
		else {			
			maxi = ans;
			int chotu = a[k];
			//k++;
			for(;k<n;k++) {
				//chotu = (chotu+1)%maxi;
				//cout << a[k] << " " << chotu << "\n";
				if(a[k] == chotu) {
					//chotu = (chotu+1)%maxi;
					if(chotu == maxi) {
						chotu = 1;
					}
					else {
						chotu++;
					}
					continue;
				}
				if(a[k] == -1) {
					//chotu = (chotu+1)%maxi;
					if(chotu == maxi) {
						chotu = 1;
					}
					else {
						chotu++;
					}
					continue;
				}
				flag = 1;
				break;
			}
			if(flag) {
				//cout << "hi\n";
				cout << "impossible\n";
				continue;
			}
			// precheck
			int flag2 = 0;
			int index = pos;
			int val = a[pos];
			//cout << index << " " << val << "\n";
			while(index > 0) {
				index--;
				if(val > 1) {
					val--;
				}
				else {
					val = maxi;
				}
				//cout << index << " " << val << "\n";
				if(a[index] == val) {
					continue;
				}
				if(a[index] == -1) {
					continue;
				}
				flag2 = 1;
				break;
			}
			if(flag2) {
				//cout << "hi\n";
				cout << "impossible\n";
				continue;
			}
			cout << maxi << "\n";
		}
	}	
}	