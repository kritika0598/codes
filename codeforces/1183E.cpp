#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


int solution(vector<int>& A, int k) 
{ 
    // seiz of the vector 
    // which does is constant 
    const int N = A.size(); 
  
    // bases cases 
    if (N < k || N < 1 || k < 1) 
        return 0; 
    if (N == k) 
        return 1; 
  
    // Prepare arrays for recursion 
    vector<int> v1(N, 0); 
    vector<int> v2(N, 0); 
    vector<int> v3(N, 0); 
  
    // initiate separately for k = 1 
    // intiate the last element 
    v2[N - 1] = 1; 
    v3[A[N - 1] - 1] = 1; 
  
    // initiate all other elements of k = 1 
    for (int i = N - 2; i >= 0; i--) { 
  
        // initialize the front element 
        // to vector v2 
        v2[i] = v2[i + 1]; 
  
        // if element v[a[i]-1] is 0 
        // then increment it in vector v2 
        if (v3[A[i] - 1] == 0) { 
            v2[i]++; 
            v3[A[i] - 1] = 1; 
        } 
    } 
  
    // iterate for all possible values of K 
    for (int j = 1; j < k; j++) { 
  
        // fill the vectors with 0 
        fill(v3.begin(), v3.end(), 0); 
  
        // fill(v1.begin(), v1.end(), 0) 
        // the last must be 0 as from last no unique 
        // subarray can be formed 
        v1[N - 1] = 0; 
  
        // Iterate for all index from which unique 
        // subsequences can be formed 
        for (int i = N - 2; i >= 0; i--) { 
  
            // add the number of subsequence formed 
            // from the next index 
            v1[i] = v1[i + 1]; 
  
            // start with combinations on the 
            // next index 
            v1[i] = v1[i] + v2[i + 1]; 
  
            // Remove the elements which have 
            // already been counted 
            v1[i] = v1[i] - v3[A[i] - 1]; 
  
            // Update the number used 
            v3[A[i] - 1] = v2[i + 1]; 
        } 
  
        // prepare the next iteration 
        // by filling v2 in v1 
        v2 = v1; 
    } 
  
    // last answer is stored in v1 
    return v1[0]; 
} 
  
// Function to push the vector into an array 
// and print all the unique subarrays 
void solve(int a[], int n, int k) 
{ 
    vector<int> v; 
  
    // fill the vector with a[] 
    v.assign(a, a + n); 
  
    // Function call to print the count 
    // of unique susequences of size K 
    cout << solution(v, k); 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,K;
	cin>>N>>K;
	string str;
	cin>>str;
	lli cost=0;
	//s.insert(str);
	bool flag=true;
	lli i=1;
	lli s=1;
	while(s<=K)
	{
		lli z=solve(s,N,N-i)
		cost+=(z*i);
		s=s+z;
		
		if(s>K)
		{
			while(s!=K)
			{
				s--;
				cost=cost-i;
			}
		}
		if(s==K)
		{
			cout<<cost<<endl;
			return 0;
		}

	}	
}