
// CPP Program to find the Number of Subsets that  
// have sum between A and B 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

  
/* Function to Generate all subsets of a set 
   start --> Starting Index of the Set for the  
             first/second half Set 
   setSize --> Number of element in half Set 
   S --> Original Complete Set 
   res --> Store the subsets sums */
void generateSubsets(lli start, lli setSize, lli S[], 
                                    vector<lli>& res) 
{ 
    // setSize of power set of a set with setSize 
    // N is (2^n - 1) 
    lli pow_setSize = pow(2, setSize); 
  
    // Store the sum of particular subset of set 
    lli sum; 
  
    // Run from counter 000..0 to 111..1 
    for (lli counter = 0; counter < pow_setSize; counter++) { 
  
        // set the sum initially to zero 
        sum = 0; 
  
        for (lli j = 0; j < setSize; j++) { 
  
            // Check if jth bit in the counter is set 
            // If set then pront jth element from set 
            if (counter & (1 << j)) 
                sum += S[j + start]; 
        } 
  
        // Store the sum in a vector 
        res.push_back(sum); 
    } 
} 
  
lli numberOfSubsets(lli S[], lli N, lli A, lli B) 
{ 
    // Vectors to store the subsets sums 
    // of two half sets individually 
    vector<lli> S1, S2; 
  
    // Generate subset sums for the first half set 
    generateSubsets(0, N / 2, S, S1); 
  
    // Generate subset sums for the second half set 
    if (N % 2 != 0) 
        generateSubsets(N / 2, N / 2 + 1, S, S2); 
    else
        generateSubsets(N / 2, N / 2, S, S2); 
  
    // Sort the second half set 
    sort(S2.begin(), S2.end()); 
  
    // Vector Iterator for S1 and S2; 
    vector<lli>::iterator low, high; 
  
    // number of required subsets with desired Sum 
    lli ans = 0; 
  
    for (lli i = 0; i < S1.size(); i++) { 
  
        // search for lower bound 
        low = lower_bound(S2.begin(), S2.end(), A - S1[i]); 
  
        // search for upper bound 
        high = upper_bound(S2.begin(), S2.end(), B - S1[i]); 
  
        // Add up to get the desired answer 
        ans += (high - low); 
    } 
    return ans; 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    lli N,A,B;
    cin>>N>>A>>B;
    lli S[N];
    for(lli i=0;i<N;i++)
    {
        cin>>S[i];
    }
  
    // Find the number of subsets with desired Sum 
    cout << numberOfSubsets(S, N, A, B) << endl; 
    return 0; 
} 
