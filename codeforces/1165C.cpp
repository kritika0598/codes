#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;
	string s;
	cin>>s;
	string o="";
	bool flag=true;
	//bool f=false;
	lli k=0;
	for(lli i=0;i<s.length();i++)
	{
		if(flag)
		{
			//o=o+s[i];
			k++;
			flag=false;
		}
		else
		{
			if((i!=0) && (s[i-1]!=s[i]))
			{
				//o=o+s[i];
				flag=true;
			//	k++;
			}
			else
			{
				s.erase(s.begin()+i);
				i--;
			}
		}
	//	cout<<s<<" "<<i<<endl;
	}
	// for(lli i=0;i<n-1;i++)
	// {
	// 	if(flag)
	// 	{
	// 		if(s[i]!=s[i+1])
	// 		{
	// 			o=o+s[i]+s[i+1];
	// 		}
	// 		else
	// 		{
	// 			o=o+s[i];
	// 			f=true;
	// 		}
	// 		flag=false;
	// 	}
	// 	else
	// 	{
	// 	//	i++;
	// 		if(f)
	// 		{
	// 			if(o[o.length()-1]!=s[i])
	// 			{
	// 				o=o+s[i];		
	// 				f=false;
	// 				flag=true;

	// 			}
	// 		}
	// 		else
	// 		{
	// 			f=false;
	// 			flag=true;
	// 		}
	// 	}
	// 	//cout<<o<<endl;
	// }
	if(s.length()%2==0)
	{
		cout<<n-s.length()<<endl;
		cout<<s<<endl;
	}
	else
	{
		cout<<n-s.length()+1<<endl;
		for(lli i=0;i<s.length()-1;i++)
			cout<<s[i];
		cout<<endl;
	}
	
}