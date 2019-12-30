#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int findMax(int a,int b){
	if(a > b)
		return a;
	else
		return b;
}
int main(){
	int n,q,k;
	cin >> n >> q >> k;
	int arr[n+3];
	int count = 0;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		if(arr[i] == 1){
			count++;
		}
	}
	string str;
	cin >> str;
	if(count == 0 || count == n){
		for(int i=0;i<q;i++){
			if(str[i] == '?'){
				if(count > k)
					cout <<k << "\n";
				else
					cout << count << "\n";
			}
		}
	}
	else{
		int fx = -1,fy = -1,lx = -1,ly = -1;
		int pre = 1,post = n;
		if(arr[1] == 1 && arr[n] == 1){
			fx = 1;
			ly = n;
			while(arr[pre] == 1){
				pre++;
			}
			fy = pre-1;
			while(arr[post] == 1){
				post--;
			}
			lx = post+1;
		}
		int lc = 0;
		int max = -1;
		int submax = -1;
		int start = -1;		
		for(int i = pre;i<= post;i++){
			if(arr[i] == 1){
				lc++;
				if(lc > max){
					start = i-lc+1;
					max = lc;
				}
			}
			else if(arr[i] == 0){
				lc = 0;
			}
		}
		lc = 0;
		if(start != -1){
			for(int i=pre;i<start;i++){
				if(arr[i] == 1){
					lc++;
					if(lc > submax){
						submax = lc;
					}
				}
				else if(arr[i] == 0){
					lc = 0;
				}
			}
			lc = 0;
			for(int i=start+max;i<=post;i++){
				if(arr[i] == 1){
					lc++;
					if(lc > submax){
						submax = lc;
					}
				}
				else if(arr[i] == 0){
					lc = 0;
				}
			}
		}
		int lazy = 0;
		int len1 = 0;
		int len2 = 0;
		for(int i=0;i<q;i++){
			if(str[i] == '!'){
				lazy = lazy + 1;
			}
			else{
				if(fx != -1){
					fx = (fx + lazy) % n;
					fy = (fy + lazy) % n;
					lx = (lx + lazy) % n;
					ly = (ly + lazy) % n;
					if(fx == 0)
						fx = n;
					if(fy == 0)
						fy = n;	
					if(lx == 0)
						lx = n;
					if(ly == 0)
						ly = n;
				}
			
				if(max != -1){
					start = (start+lazy) % n;
					if(start == 0)
						start = n;
				}
				if(fx != -1){
					if(fx <= fy && fy < lx && lx <= ly){
						len1 = findMax(fy-fx + 1,ly-lx +1);
					}
					else if(ly >= 1 && ly < fx && lx <= n && lx > ly ){
						len1 = findMax(fy,n-lx+1);
						//cout  << fx << " " << fy << " " << lx << " " << ly << " " << len1 <<  "\n";
					}
					else if(fx <= fy && lx <= ly && fx > ly){
						len1 = fy-lx+1;				
						//cout << "HI " << fx << " " << fy << " " << lx << " " << ly << " " << len1 <<  "\n";
						
					}
					else if(lx <= ly && fx > ly && fx >= fy && fy >= 1){
						len1 = findMax(n-lx+1,fy);
					}
				}
				if(max != -1){
					if(start + max - 1 <= n){
						len2 = max;
					}
					else{
						int val = (start + max - 1) % n;
						len2 = findMax(n-start+1,val);
						len2 = findMax(len2,submax);
					}
				}
				int gr = findMax(len1,len2);
				if(gr >= k)
					cout << k << "\n";
				else
					cout << gr << "\n";
					
				lazy = 0;
			}
		}
						 
	
		
	}
}