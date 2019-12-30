// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// typedef long long int lli;

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	lli Arr[31];
// 	Arr[0]=1;
// 	for(lli i=1;i<31;i++)
// 	{
// 		if(i%2!=0)
// 			Arr[i]=0;
// 	}
// 	Arr[2]=3;
// 	for(lli i=4;i<31;i=i+2)
// 	{
// 		Arr[i]=Arr[2]*Arr[i-2];
// 		for(lli j=2;j<=i-4;j=j+2)
// 		{
// 			Arr[i]+=2*Arr[j];
// 		}
// 		Arr[i]=Arr[i]+2;
// 	}
// 	while(1)
// 	{
// 		lli N;
// 		cin>>N;
// 		if(N==-1)
// 			return 0;

// 		cout<<Arr[N]<<endl;		
// 	}

// }

    #include <stdio.h>
    int main() {
    	int n, T[31], F[31];
    	T[0]=1; F[0]=0;
    	//memoise the values first
    	for(int i=1; i<=30; i++){
    		T[i] = ((i>=2)?3*T[i-2]:0) + ((i>=3)?2*F[i-3]:0);
    		F[i] = T[i-1] + ((i>=2)?F[i-2]:0);
    	}
    	while(true){
    		scanf("%d",&n);
    		if(n==-1) break;
    		printf("%d\n",T[n]);
    	}
    	return 0;
    }