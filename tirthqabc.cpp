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
		int flag = 0;
		int n;
		cin >> n;
		int a[n+1] = {0};
		int b[n+1] = {0};
		for(int i=1;i<=n;i++) {
			cin >> a[i];
		}
		for(int i=1;i<=n;i++) {
			cin >> b[i];
		}
		int diff[n+1] = {0};
		for(int i=1;i<=n;i++) {
			diff[i] = b[i] - a[i];
			if(diff[i] < 0) {
				flag = 1;
			}
		}
		if((diff[n] % 3) != 0) {
			flag = 1;
		}
		if((diff[n-1] % 2) != 0) {
			flag = 1;
		}
		if(flag) {
			cout << "NIE\n";
			continue;
		}
		// cout << "Diff\n";
		// for(int i=1;i<=n;i++) {
		// 	cout << diff[i] << " ";
		// }
		// cout << "\n";
		for(int i=1;i<=(n-2);i++) {
			// if((diff[i+1]% 2) != 0) {
			// 	flag = 1;
			// 	break;
			// }
			// if((diff[i+2] % 3) != 0) {
			// 	flag = 1;
			// 	break;
			// }
			if(diff[i] != 0) {
				diff[i+1] -= (diff[i]*2);
				diff[i+2] -= (diff[i]*3);
				diff[i] = 0;
				if(diff[i+1] < 0) {
					flag = 1;
					break;
				}
				if(diff[i+2] < 0) {
					flag = 1;
					break;
				}
			}
		}
		if(flag) {
			cout << "NIE\n";
		}
		else {
			cout << "TAK\n";
		}
	}		
}