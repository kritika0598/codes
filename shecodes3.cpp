#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int mod(string num, int a) 
{ 
    // Initialize result 
    int res = 0; 
  
    // One by one process all digits of 'num' 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} 

string solve (vector<int> A) {
    lli N=A.size();
    N=N/2;
    lli ans=0;
    lli p=11;
    string s="";
    for(lli i=0;i<N;i++)
    {
        lli x=log10(A[i]);
        x=A[i]/(pow(10,x));
        s=s+to_string(x);
    }
    
    for(lli i=N;i<A.size();i++)
    {
        s=s+to_string(A[i]%10);
    }
  //  cout<<ans<<endl;
    int z=mod(s,11);
    if(z==0)
    {
        return "OUI";
    }
    else
        return "NON";
   // Write your code here
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    string out_;
    out_ = solve(A);
    cout << out_;
}