#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int x[3];
		int y[3];
		int z[3];
		int rank[3];	
		for(int i=0;i<3;i++){
			cin >> x[i] >> y[i] >> z[i];
		}
		int max = -1;
		for(int i=0;i<3;i++){
			if(x[i] > x[ (i+1) % 3] && x[i] > x[ (i+2) % 3 ]){
				max = i;
				break;
			}
			if(y[i] > y[ (i+1) % 3] && y[i] > y[ (i+2) % 3 ]){
				max = i;
				break;
			}
			if(z[i] > z[ (i+1) % 3] && z[i] > z[ (i+2) % 3 ]){
				max = i;
				break;
			}
		}
		if(max == -1){
			cout << "no\n";
			continue;
		}
		int val1;
		int val2;
		int temp;
		if(max == 0){
			val1 = 1;
			val2 = 2;
		}
		if(max == 1){
			val1 = 2;
			val2 = 0;
		}
		if(max == 2){
			val1 = 0;
			val2 = 2;
		}
		if( !( (x[max] >= x[val1] && x[max] >= x[val2]) && (y[max] >= y[val1] && y[max] >= y[val2])  && (z[max] >= z[val1] && z[max] >= z[val2])  )){
			cout << "no\n";
			continue;
		}
		if( ((x[val1] >= x[val2]) && (y[val1] >= y[val2]) && (z[val1] >= z[val2])) && ((x[val1] > x[val2]) || (y[val1] > y[val2]) || (z[val1] > z[val2])) ) {
			cout << "yes\n";
			continue;
		}
		temp = val1;
		val1 = val2;
		val2 = temp;		
		if( ((x[val1] >= x[val2]) && (y[val1] >= y[val2]) && (z[val1] >= z[val2])) && ((x[val1] > x[val2]) || (y[val1] > y[val2]) || (z[val1] > z[val2])) ){
			cout << "yes\n";
			continue;
		}
		else{
			cout << "no\n";
			continue;
		}
	}
			

}