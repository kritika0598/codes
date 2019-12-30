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

	string s;
	cin>>s;

	lli moves=N-11;
	queue<lli> pos;
	vector<char> st;
	vector<char> :: iterator itr;
	for(lli i=0;i<N;i++)
	{
		if(s[i]=='8')
		{
			pos.push(i+1);
		}
		st.push_back(s[i]);
	}


	lli turn=moves/2;
	lli x=0;
	lli cnt=0;
	lli z=moves;
	bool flag=true;
	if(pos.size()<=turn)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		while(moves)
		{
			if(pos.empty())
			{
				cout<<"NO"<<endl;
				return 0;
			}
			if(flag)
			{
				if(st[0]!='8')
				{
					st.erase(st.begin());
				}
				else
				{
					x++;
				}
				moves--;
				flag=false;
			}
			else
			{
				pos.pop();
				itr=find(st.begin(),st.end(),'8');
				//lli x=itr-st.begin();

				//cout<<x<<endl;
				st.erase(itr);
				moves--;
				flag=true;
			}
		}

		if(find(st.begin(),st.end(),'8')-st.begin()<=x)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}

	}

}