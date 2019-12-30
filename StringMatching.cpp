#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	lli n;
	cin>>n;
	char Arr[n];
	for(lli i=0;i<n;i++)
	{
		cin>>Arr[i];
	}
	lli l=0,r=0, ans=0;
	map<char,lli>cnt;
	set<char> t;
	lli N=s.length();
	set<char> :: iterator itr;
	bool flag=true;
	while(l<N)
	{
		while(r<N && t.size()<n)
		{
			for(lli i=0;i<n;i++)
			{
				if(s[r]==Arr[i])
				{
					t.insert(Arr[i]);
					cnt[Arr[i]]++;
					
					break;
				}	

			}
			r++;
			// cout<<"HELLO"<<endl;
		}
		
		 // cout<<l<<" "<<r<<endl;
			
		if(t.size()==n)
		{
			ans=ans+(N-r+1);
			if(cnt[s[l]]==1)
				t.erase(s[l]);
			cnt[s[l]]--;

			l++;

		}
		else
			break;

	}

	cout<<ans<<endl;

}