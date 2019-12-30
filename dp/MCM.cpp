
/* A naive recursive implementation that simply 
  follows the above optimal substructure property */
#include<stdio.h> 
#include<limits.h> 
  
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
int m[100][100];
int MatrixChainOrder(int p[], int i, int j) 
{ 
    if(i == j) 
        return 0; 
    if(m[i][j]!=-1)
        return m[i][j];
    int k; 
    int min = INT_MAX; 
    int count; 
  
    // place parenthesis at different places between first 
    // and last matrix, recursively calculate count of 
    // multiplications for each parenthesis placement and 
    // return the minimum count 
    for (k = i; k <j; k++) 
    { 
        count = MatrixChainOrder(p, i, k) + 
                MatrixChainOrder(p, k+1, j) + 
                p[i-1]*p[k]*p[j]; 
  
        if (count < min) 
            min = count; 
    } 
  
    // Return minimum count 
    return min; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            m[i][j]=-1;
        }
    }
    printf("Minimum number of multiplications is %d ", 
                          MatrixChainOrder(arr, 1, n-1)); 
  
    getchar(); 
    return 0; 
} 
