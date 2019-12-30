#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n1-1; i>=0; i--) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining digits of str2[] 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	string s;
	cin>>s;
	lli mini=INT_MAX;
	lli i=0,j=0;
	bool flag=true;
	if(N%2==0)
	{
		i=N/2;
		j=N/2;
		while(flag)
		{
			if(s[i]=='0' && s[j]=='0')
			{
				i++;
				j--;
				continue;
			}
			else if(s[j]=='0')
			{
				string a=s.substr(0,i);
				string b=s.substr(i);
				string c=findSum(a,b);
				cout<<c<<endl;
				return 0;
			}
			else if(s[i]=='0')
			{
				string a2=s.substr(0,j);
				string b2=s.substr(j);
				string c2=findSum(a2,b2);
				cout<<c2<<endl;
				return 0;
			}
			
			string a=s.substr(0,i);
			string b=s.substr(i);
			string c=findSum(a,b);
			string a2=s.substr(0,j);
			string b2=s.substr(j);
			string c2=findSum(a2,b2);
			if(isSmaller(c,c2))
				cout<<c<<endl;
			else
				cout<<c2<<endl;
			return 0;
		}
		
	}
	if(N%2!=0)
	{
		i=N/2;
		j=N/2+1;
		while(flag)
		{
			if(s[i]=='0' && s[j]=='0')
			{
				i++;
				j--;
				continue;
			}
			else if(s[j]=='0')
			{
				string a=s.substr(0,i);
				string b=s.substr(i);
				string c=findSum(a,b);
				cout<<c<<endl;
				return 0;
			}
			else if(s[i]=='0')
			{
				string a2=s.substr(0,j);
				string b2=s.substr(j);
				string c2=findSum(a2,b2);
				cout<<c2<<endl;
				return 0;
			}
			
			string a=s.substr(0,i);
			string b=s.substr(i);
			string c=findSum(a,b);
			string a2=s.substr(0,j);
			string b2=s.substr(j);
			string c2=findSum(a2,b2);
			if(isSmaller(c,c2))
				cout<<c<<endl;
			else
				cout<<c2<<endl;
			return 0;
		}
		
	}

}