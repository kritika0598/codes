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
		string x,y;
		cin>>x>>y;
		string a,b;
		lli n=x.length();
		lli k=0;
		for(lli i=n-1;i>=0;i--)
		{
			a+=x[i];
			//k++;
		}
		n=y.length();
		k=0;
		for(lli i=n-1;i>=0;i--)
		{
			b+=y[i];
			//k++;
		}
		int p= stoi(a);
		int q= stoi(b);
	//	cout<<p<<" "<<q<<endl;
		p=p+q;

		vector<lli> v;
		bool flag=true;
		while(p!=0)
		{
			if(p%10==0 && flag)
			{
				p=p/10;
			}
			if(p%10==0 && !flag)
			{
				v.push_back(p%10);
				p=p/10;
			}
			else if(p%10!=0)
			{
				v.push_back(p%10);
				p=p/10;
				flag=false;
			}
			
		}

		for(lli i=0;i<v.size();i++)
		{
			cout<<v[i];
		}
		cout<<endl;
	}	
}