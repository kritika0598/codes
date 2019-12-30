#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct st {
    int x;
    int y;
    int f1;
    int f2;
    int f3;
    int f4;
};

void solve() {
    int n;
    cin >> n;
    int lx = -1e5;
    int hx = 1e5;
    int ly = -1e5;
    int hy = 1e5;
    st a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i].x >> a[i].y >> a[i].f1 >> a[i].f2 >> a[i].f3 >> a[i].f4;
    }
    for(int i=0;i<n;i++) {
        if(a[i].x < lx && a[i].f3 == 0) {
            cout << "0\n";
            return;
        }
        if(a[i].x > hx && a[i].f1 == 0) {
            cout << "0\n";
            return;
        }
        if(a[i].y < ly && a[i].f2 == 0) {
            cout << "0\n";
            return;
        }
        if(a[i].y > hy && a[i].f4 == 0) {
            cout << "0\n";
            return;
        }
        if(a[i].f1 == 0) {
            lx = max(a[i].x,lx);
        }
        if(a[i].f2 == 0) {
            hy = min(a[i].y,hy);
        }
        if(a[i].f3 == 0) {
            hx = min(a[i].x,hx);
        }
        if(a[i].f4 == 0) {
            ly = max(a[i].y,ly);
        }
    }
    if(lx > hx || ly > hy) {
        cout << "0\n";
        return;
    }
    cout << 1 << " " << lx << ' ' << ly << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--) {
        solve();
    }       
}