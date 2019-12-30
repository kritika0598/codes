#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli k=1;
	while(1)
	{
		string s;
		cin>>s;
		if(s[0]=='-')
			return 0;
		vector<char> v;
		vector<char> :: iterator it;
		lli count=0;
		if(s[0]=='}')
			count++;
		for(lli i=0;i<s.length();i++)
		{
			it=v.end()-1;
			if(i==0)
				v.push_back(s[0]);
			else
			{
				if(s[i]=='}')
				{
					if (*it=='{')
						v.erase(it);
					else
						v.push_back(s[i]);
				}

				else
				{
					v.push_back(s[i]);
				}

			} 
		}
		lli count1=0;
		lli count2=0;
		lli ans=0;
		while(v.size()!=0)
		{
			it=v.end()-1;
			lli b=*it;
			v.erase(it);
			it=v.end()-1;
			if(b==*it)
				ans=ans+1;
			else
				ans=ans+2;
			v.erase(it);


		}

		cout<<k<<". "<<ans<<endl;

		// for(it=v.begin();it!=v.end();++it)
		// {
		// 	if(*it=='{')
		// 		count1++;
		// 	else
		// 		count2++;
		// 	//cout<<*it;
		// }
		// if(count1==0 || count2==0)
		// {
		// 	cout<<k<<". "<<count1/2+count2/2<<endl;
		// }
		// else if(count1==1 && count2==1)
		// {
		// 	cout<<k<<". "<<2<<endl;
		// }
		// else if(count1==count2)
		// {
		// 	cout<<k<<". "<<count1<<endl;
		// }
		// else
		// {
		// 	lli cv=min(count1,count2);
		// 	lli vc=max(count1,count2)-min(count1,count2);
		// 	cout<<k<<". "<<(2*cv)+(vc/2)<<endl;
		// }
		k++;
		//cout<<endl;
		//cout<<v.size()/2<<endl;
	}
		
}