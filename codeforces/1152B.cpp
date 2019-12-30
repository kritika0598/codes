#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x;
	cin>>x;
	int p=40;
	int m=0;
	vector<int> v;
	if (((x + 1) & x) == 0) 
	{
		cout<<0<<endl;
        return 0; 
	}
    else
    {
    	while(p--)
    	{
    		if (((x + 1) & x) == 0) 
    		{
    			cout<<m<<endl;
    			for(int i=0;i<v.size();i++)
    			{
    				cout<<v[i]<<" ";
    			}
    			break;
    		}
    		int pos = 0; 
    		for (int temp=x, count=0; temp>0; temp>>=1, count++) 
        		if ((temp & 1) == 0)  
            		pos = count; 
    		//cout<<pos+1<<endl;
    		v.push_back(pos+1);
    		int d=pow(2,pos+1)-1;
    		//cout<<d<<endl;
    		x=x^d;
    		//cout<<x<<endl;
    		m++;
    		if (((x + 1) & x) == 0) 
    		{
    			cout<<m<<endl;
    			for(int i=0;i<v.size();i++)
    			{
    				cout<<v[i]<<" ";
    			}
    			break;
    		}
    		x++;
    		//cout<<x<<endl;
    		m++;
    		if (((x + 1) & x) == 0) 
    		{
    			cout<<m<<endl;
    			for(int i=0;i<v.size();i++)
    			{
    				cout<<v[i]<<" ";
    			}
    			break;
    		}
    		
    	}
    }
}