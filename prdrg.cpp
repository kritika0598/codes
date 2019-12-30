#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int lli;


lli modpow(lli base, lli exp, lli modulus) {
  base %= modulus;
  lli result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	lli Arr[26];
	Arr[1]=1;
	Arr[2]=1;
	for(lli i=3;i<26;i++)
	{
		Arr[i]=Arr[i-1]+Arr[i-2]+Arr[i-2];
	}
	while(T--)
	{
		lli N;
		cin>>N;
		cout<<Arr[N]%mod<<" "<<(modpow(2,N,mod))<<" ";
	}
		
}