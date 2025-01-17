/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "fhhi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<bits/stdc++.h>
using namespace  std;
typedef long long int lli;

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    string s;
    cin>>s;
    lli sum[n+1];
    lli num[n+1];
    lli m=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
            arr[i]=1;
        else if(s[i]=='0')
            arr[i]=-1;
        else
        {
            arr[i]=0;
            m++;
        }
        if(i==0)
        {
            sum[0]=arr[0];
        }
        else
            sum[i]=sum[i-1]+arr[i];
        num[i]=m;
    }
    
    lli dp[100005][100005];
    lli x=0;
    lli max=-1;
    lli a,b,dif;
    bool flag=true;
    for(lli i=0;i<n;i++)
    {
        dp[0][i]=sum[i];
    }
    
    for(lli i=0;i<n-1;i++)
    {
        for(lli j=i+1;j<n;j++)
        {
            
            dp[i][j]=sum[j]-sum[i-1];
            if(dp[i][j]==0 && m==0)
            {
                lli max=j-i+1;
                flag=false;
            }
        }
    }
    
    
    if(m==0  && flag)
    {
        cout<<-1<<endl;
    }
    else if(m==0 && !flag)
    {
        cout<<max<<endl;
    }
    else
    {
        for(lli i=0;i<n-1;i++)
        {
            for(lli j=i+1;j<n;j++)
            {
                a=sum[j]-sum[i-1];
                //a=dp[i][j];
                b=num[j]-num[i-1];
                dif=0-a;
                if(abs(dif)<=b)
                {
                    if((b-abs(dif))%2==0)
                    {
                        if((j-i)>max)
                            max=j-i+1;
                    }
                }
            }
        }
        
        cout<<max<<endl;
    }
    
    
}