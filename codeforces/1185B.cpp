#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	while(N--)
	{
		bool flag=true;
		string s1,s2;
		cin>>s1>>s2;
		if(s2.length()<s1.length())
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(s1.length()==s2.length())
		{
			if(s1==s2)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else
		{
			queue<pair<char,int>> st;
			//cout<<s1<<" "<<s2<<endl;
			int p=1;
			for(lli i=0;i<s1.length()-1;i++)
			{
				if(s1[i]==s1[i+1])
				{
					p++;
				}
				else
				{
					st.push({s1[i],p});
					p=1;
				}				
			}
			st.push({s1[s1.length()-1],p});
			char z='_';
			int t=0;
			//map<char,lli> m;
			for(lli i=0;i<s2.length();)
			{
				z=st.front().first;
				int l=st.front().second;
				//cout<<i<<" "<<z<<" "<<l<<endl;
				if(s2[i]==z)
				{
					while(i<s2.length() && s2[i]==z)
					{
						i++;
						t++;
						//cout<<i<<" "<<t<<endl;
					}
					if(t%(l)==0)
					{
						// if(m[z]==0)
						// {
						// 	m[z]=(t/l);
						// }
						// else
						// {
						// 	if((t/l)!=m[z])
						// 	{
						// 		cout<<"NO"<<endl;
						// 		flag=false;
						// 		break;
						// 	}
						// }
						st.pop();
						t=0;
					}
					else
					{
						cout<<"NO"<<endl;
						flag=false;
						break;
					}
					//i--;
					
				}
				else
				{
					cout<<"NO"<<endl;
					flag=false;
					break;
				}
				//cout<<i<<" ";
			}
			if(flag)
			{
				cout<<"YES"<<endl;
			}
		}
	}
}