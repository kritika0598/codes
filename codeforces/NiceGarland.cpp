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
	string S;
	cin>>S;
	if(N==1)
	{
		cout<<0<<endl;
		cout<<S<<endl;
		return 0;
	}
	if(N==2)
	{
		if(S[0]==S[1])
		{
			cout<<1<<endl;
			if(S[0]=='R')
				cout<<S[0]<<"G"<<endl;
			else if(S[0]=='B')
				cout<<S[0]<<"R"<<endl;
			else
				cout<<S[0]<<"R"<<endl;
			return 0;
		}
	}
	//vector<string> type[6];
	string type[7];

	for(lli i=0;i<N;i++)
	{
		if(i%3==0)
			type[1]+='R';
		else if(i%3==1)
			type[1]+='G';
		else
			type[1]+='B';
	}

	for(lli i=0;i<N;i++)
	{
		if(i%3==0)
			type[2]+='R';
		else if(i%3==1)
			type[2]+='B';
		else
			type[2]+='G';
	}

		for(lli i=0;i<N;i++)
	{
		if(i%3==0)
			type[3]+='B';
		else if(i%3==1)
			type[3]+='G';
		else
			type[3]+='R';
	}

		for(lli i=0;i<N;i++)
	{
		if(i%3==0)
			type[4]+='B';
		else if(i%3==1)
			type[4]+='R';
		else
			type[4]+='G';
	}

		for(lli i=0;i<N;i++)
	{
		if(i%3==0)
			type[5]+='G';
		else if(i%3==1)
			type[5]+='R';
		else
			type[5]+='B';
	}

		for(lli i=0;i<N;i++)
	{
		if(i%3==0)
			type[6]+='G';
		else if(i%3==1)
			type[6]+='B';
		else
			type[6]+='R';
	}

	// for(lli i=1;i<=6;i++)
	// {
	// 	cout<<type[i]<<endl;
	// }

	lli count=0;
	lli ans=INT_MAX;
	lli ind=INT_MAX;
	for(lli i=1;i<=6;i++)
	{
		count=0;
		for(lli j=0;j<N;j++)
		{
			if(type[i][j]!=S[j])
				count++;
		}
		if(count<ans)
		{
			ans=count;
			ind=i;
		}	

	}

	cout<<ans<<endl;
	for(lli i=0;i<N;i++)
	{
		cout<<type[ind][i];
	}
	cout<<endl;
	

}