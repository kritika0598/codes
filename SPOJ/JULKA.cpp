#include <stdio.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
         string a,b;

    /*This method adds two Numbers represnted using strings*/
    string add(string v1, string v2)// v1 = v1+v2;
    {
         int i,d,c=0;
         int l1=(v1).length();
         int l2=(v2).length();
         if(l1<l2)
        {
            for(i=l1;i<l2;i++) 
              v1=v1+'0';
        }
        else
        {
            for(i=l2;i<l1;i++) 
                v2=v2+'0';
        }
        
         for(i=0;i<l1||i<l2;i++)
         {
              d=(v1[i]-'0')+(v2[i]-'0')+c;
              c=d/10;
              d%=10;
              v1[i]='0'+d;
         }
         while(c)
         {
              v1[i]='0'+(c%10);
              c/=10;
              i++;
         }
         v1[i]='\0';
         v2[l2]='\0';
         return v1;
    }
    /*This function subtracts two numbers represnted using string*/
    string subs(string v1, string v2)
    // v1=v1-v2;
    {
         int i,d,c=0;
         int l1=(v1).length();
         int l2=(v2).length();
         for(i=l2;i<l1;i++)
              v2=v2+'0';
         for(i=0;i<l1;i++)
         {
              d=(v1[i]-'0'-c)-(v2[i]-'0');
              if(d<0)
              {
                   d+=10; 
                   c=1;
              }
              else c=0;
              v1[i]='0'+d;
         }
         v2[l2]='\0';
         i=l1-1;
         while(i>0 && v1[i]=='0') 
              i--;
         v1[i+1]='\0';
         return v1;
    }
    /*This function divides a number represented using string by a constant*/
    int divi(string v, int q)
    // returns the reminder
    {
         int i,l=(v).length();
         int c=0,d;
         for(i=l-1;i>=0;i--)
         {
              d=c*10+(v[i]-'0');
              c=d%q; d/=q; v[i]='0'+d;
         }
         i=l-1;
         while(i>0 && v[i]=='0') 
              i--;
         v[i+1]='\0';
         return c;
    }
    /*This function reverses the number*/
    string rev(string v) 
    {
         int l=(v).length();
         int i; char cc;
         for(i=0;i<l-1-i;i++)
         {
              cc=v[i];v[i]=v[l-1-i];v[l-i-1]=cc;
         }

         return v;
    }
    /*All the above codes are predefined given in the pdf link above on Pg no. 25*/
    int main() {
         for(int i=0; i<10 ;++i)
         {
              /*Inputing numbers as strings*/
              cin>>a;
              cin>>b;
              
              /*We can apply the above functions
         only if the numbers are represented 
            in reverse manner*/ 
              a=rev(a);
              b=rev(b);
             
              /*Adding both numbers*/ 
              a=add(a,b);
              /*we divide to get one answer*/
              a=divi(a,2);
             
              /*Reverse and output answer*/ 
              a=rev(a);
              cout<<a<<endl;
              
              /*To calculate further, we need to 
         again reverse the number*/ 
              a=rev(a);
              a=subs(a,b);
              /*Reverse and output second answer*/  
              a=rev(a);
              cout<<a<<endl;
              
              
         }
         return 0;
    }