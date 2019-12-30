#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool visited[1000005];
lli BIT[1000005];
lli N;
void update(lli ind,lli val)
{
	while(ind<=N)
	{
		BIT[ind]+=val;
		ind=ind+ind&(-ind);
	}

}

lli query(lli ind)
{
	lli sum=0;
	while(ind>0)
	{
		sum=sum+BIT[ind];
		ind-=ind&(-ind);
	}
	return sum;
}
bool compare(const pair<lli,lli> &l,const pair<lli,lli> &r) {
    return l.second < r.second;
}
bool comp(const pair<lli,lli> &l,const pair<lli,lli> &r) {
	if(l.first==r.first)
		return l.second>r.second;
    return l.first< r.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		cin>>N;
		if(N==-1)
			return 0;
		memset(BIT,0,sizeof(BIT));
		vector<pair<lli,lli>> start1;
		vector<lli> start2;
		vector<pair<lli,lli>> end1;
		pair<lli,lli> p;
		vector<lli> end2;
		vector<lli> :: iterator itrl;
		vector<pair<lli,lli>> :: iterator itru;
		for(lli i=0;i<N;i++)
		{
			lli x,y;
			cin>>x>>y;
			start1.push_back(make_pair(x,y));
			start2.push_back(x);
			end1.push_back(make_pair(x,y));
			end2.push_back(y);
		}

		sort(start1.begin(),start1.end(),comp);
		sort(end1.begin(),end1.end(),compare);
		sort(start2.begin(),start2.end());
		sort(end2.begin(),end2.end());
		lli k=1;
		for(lli i=N-1;i>=0;i--)
		{
			itrl=lower_bound(start2.begin(),start2.end(),end2[i]);
			p=end1[i];
			itru=find(start1.begin(),start1.end(),p);
			lli b=itru-start1.begin();
			//cout<<b<<endl;
			update(N-b,1);
			//itru=upper_bound(start1.begin(),start1.end(),end1[i]);	
			if(itrl!=start2.end())
			{
				lli x=itrl-start2.begin();
			//	cout<<N-x<<endl;
				lli z=query(N-x);
				//cout<<N-x<<" "<<z<<endl;
				update(N-b,z);
			}
			//cout<<N-b<<" "<<query(N-b)<<endl;	
			//k++;	

		}
		lli M=query(N-1)+BIT[N];
		// cout<<M<<endl;
		// for(lli i=1;i<=N;i++)
		// {
		// 	cout<<BIT[i]<<" ";
		// }
		// cout<<endl;
		lli Ans[8];
		for(lli i=7;i>=0;i--)
		{
			Ans[i]=M%10;
			M=M/10;
		}
		for(lli i=0;i<8;i++)
		{
			cout<<Ans[i];
		}
		cout<<endl;
		//cout<<query(N)<<endl;

	}
}