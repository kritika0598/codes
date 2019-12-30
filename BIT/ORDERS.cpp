#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N;
		cin>>N;
		lli Arr[N];
		for(lli i=0;i<N;i++)
		{
			cin>>Arr[i];
		}
		//vector<lli> v[N+1];
		lli v[N];
		set<lli> s;
		vector<lli> vc;
		vector<lli> :: iterator itr;
		for(lli i=0;i<N;i++)
		{
			vc.push_back(i);
		}
		// lli x=N-1 - Arr[N-1];
		// a[x]=N;
		// //cout<<x<<" "<<N<<endl;
		// for(lli i=N-1;i>x;i--)
		// {
		// 	s.insert(i);
		// }
		// for(lli i=N-2;i>=0;i--)
		// {
		// 	if(Arr[i]==0)
		// 	{
		// 		if(v[i].size()==0)
		// 		{
		// 			v[i].push_back(i+1);
		// 		//	cout<<i<<" "<<i+1<<endl;
		// 			if(s.find(i)!=s.end())
		// 			{
		// 				s.erase(s.find(i));
		// 			}
		// 		}
		// 		else
		// 		{
		// 			lli z= *s.upper_bound(i);
		// 			s.erase(s.upper_bound(i));
		// 			v[z].push_back(i+1);
		// 			//cout<<z<<" "<<i+1<<endl;
		// 			if(s.find(z)!=s.end())
		// 			{
		// 				s.erase(s.find(z));
		// 			}
		// 		}
		// 	}
		// 	else
		// 	{

		// 		x=i-Arr[i];
		// 		if(v[x].size()==0)
		// 		{
		// 			v[x].push_back(i+1);
		// 			//cout<<x<<" "<<i+1<<endl;
		// 			for(lli j=i;j>x;j--)
		// 			{
		// 				if(v[j].size()==0)
		// 					s.insert(j);
		// 			}
		// 			if(s.find(x)!=s.end())
		// 			{
		// 				s.erase(s.find(x));
		// 			}
		// 		}else
		// 		{
		// 			v[i].push_back(i+1);
		// 		//	cout<<i<<" "<<i+1<<endl;
		// 			if(s.find(i)!=s.end())
		// 			{
		// 				s.erase(s.find(i));
		// 			}
		// 		}
				
		// 	}
		// }


		for(lli i=N-1;i>=0;i--)
		{
			lli x=i-Arr[i];
			v[vc[x]]=i+1;
			itr=vc.begin()+x;
			vc.erase(itr);
		}

		for(lli i=0;i<N;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
		
}