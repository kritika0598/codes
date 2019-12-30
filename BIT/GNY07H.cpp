#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n, T[1001], F[1001],F1[1001];
    T[0]=1; F[0]=0; F1[0]=0;
    T[1]=1;
    T[2]=5;
    lli N;
    for(lli i=1; i<=1000; i++)
    {
    	T[i] = ((i>=2)?4*T[i-2]:0) + T[i-1] + ((i>=2)?2*F[i-2]:0) + F1[i-2];
    		F[i] = T[i-1] + ((i>=1)?F[i-1]:0);
    		F1[i]= ((i>=2)?T[i-2]:0) + ((i>=2)?F1[i-2]:0);
    		//F1[i]= T[i-2] + ((i>=2)?F[i-4]:0);
    }
    cin>>N;
    lli i=1;
    while(N--)
    {
    	cin>>n;
    	if(n==-1) break;
    //	printf("%d\n",T[n]);
    	cout<<i<<" "<<T[n]<<endl;
    	i++;
    }
    	return 0;
}
