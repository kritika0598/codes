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
	string s1,s2;
	cin>>s1;
	cin>>s2;
	vector<pair<lli,lli>> Arr1;
	vector<pair<lli,lli>> Arr2;

	lli count=0;

	for(lli i=0;i<N;i++)
	{
		if(s1[i]=='?')
			count++;
		if(s2[i]=='?')
			count++;
		Arr1.push_back(make_pair(s1[i]-97,i+1));
		Arr2.push_back(make_pair(s2[i]-97,i+1));
	}
	sort(Arr1.begin(),Arr1.end());
	sort(Arr2.begin(),Arr2.end());

	// for(lli i=0;i<N;i++)
	// {
	// 	cout<<Arr1[i].first<<" ";
	// }
	// cout<<endl;
	// for(lli i=0;i<N;i++)
	// {
	// 	cout<<Arr2[i].first<<" ";
	// }
	// cout<<endl;
	lli c=0;
	lli k=-1,l=-1;
	for(lli i=0;i<N;i++)
	{
		if(Arr1[i].first<0)
			k++;
		else break;
	}
	for(lli i=0;i<N;i++)
	{
		if(Arr2[i].first<0)
			l++;
		else break;
	}
	//cout<<k<<" "<<l<<endl;

	vector<pair<lli,lli>> ans;
	vector<lli> u1;
	vector<lli> u2;

	lli p=k+1,q=l+1;
	for(lli i=k+1,j=l+1;i<N && j<N;)
	{
		if(Arr1[i].first==Arr2[j].first)
		{
			c++;
			i++;
			j++;
			ans.push_back(make_pair(Arr1[i-1].second,Arr2[j-1].second));
		}
		else if(Arr1[i].first<Arr2[j].first)
		{
			i++;
			u1.push_back(Arr1[i-1].second);
		}
		else
		{
			j++;
			u2.push_back(Arr2[j-1].second);
		}
		p=i;
		q=j;

	}
//	cout<<p<<" "<<q<<" "<<l<<" "<<k<<endl;
	if(p<N && p>k)
	{
		while(p<N)
		{
			u1.push_back(Arr1[p].second);
			p++;
		}
	}
	if(q<N && q>l)
	{
		while(q<N)
		{
			u2.push_back(Arr2[q].second);
			q++;
		}
	}

	// for(lli i=0;i<u1.size();i++)
	// {
	// 	cout<<u1[i]<<endl;
	// }
	// for(lli i=0;i<u2.size();i++)
	// {
	// 	cout<<u2[i]<<endl;
	// }
//	cout<<u2.size()<<" "<<u1.size()<<endl;

	if(c+count>=N)
	{
		cout<<N<<endl;
		lli x=0;
		lli s=0;
		lli t=0;
		for(lli i=0;i<ans.size();i++)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
			x++;
		}
		//cout<<x<<" "<<k<<" "<<u2.size()<<endl;
		while(x<N && s<=k && s<u2.size())
		{
			//cout<<"he"<<endl;
			cout<<Arr1[s].second<<" "<<u2[s]<<endl;
			s++;
			x++;
		}
		//cout<<x<<" "<<l<<" "<<u1.size()<<endl;
		while(x<N && t<=l && t<u1.size())
		{
			//cout<<"mw"<<endl;
			cout<<u1[t]<<" "<<Arr2[t].second<<endl;
			t++;
			x++;

		}
		while(x<N && s<=k && t<=l)
		{
			cout<<Arr1[s].second<<" "<<Arr2[t].second<<endl;
			x++;
			s++;
			t++;
		}

	}
	else
	{
		lli x=0;
		lli s=0;
		lli t=0;
		cout<<ans.size() + count<<endl;
		for(lli i=0;i<ans.size();i++)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
			x++;
		}
		while(x<ans.size()+count)
		{
			cout<<Arr1[s].second<<" "<<u2[s]<<endl;
			s++;
			x++;
			if(s==k+1 || s>u2.size()-1)
				break;
		}
		while(x<ans.size()+count)
		{
			cout<<Arr2[t].second<<" "<<u1[t]<<endl;
			t++;
			x++;
			if(t==l+1 || t>u1.size()-1)
				break;

		}
	}

}