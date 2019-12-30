// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// typedef long long int lli;

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	lli a;
// 	cout<<"? "<<1<<" "<<1<<endl;
// 	cin>>a;
// 	lli Arr[6];
// 	Arr[0]=sqrt(a);
// 	cout.flush();
// 	cout<<"? "<<2<<" "<<2<<endl;
// 	cin>>a;
// 	Arr[1]=sqrt(a);
// 	cout.flush();
// 	cout<<"? "<<3<<" "<<5<<endl;
// 	cin>>a;
// 	cout.flush();
// 	cout<<"? "<<4<<" "<<6<<endl;
// 	lli b;
// 	cin>>b;
// 	cout.flush();
// 	lli temp[6]={4,8,15,16,23,42};
// 	vector<lli> v;
// 	for(lli i=0;i<6;i++)
// 	{
// 		if(temp[i]!=Arr[0] && temp[i]!=Arr[1])
// 		{
// 			v.push_back(temp[i]);
// 		}
// 	}

// 	for(lli i=0;i<4;i++)
// 	{
// 		if(a%v[i]==0 && find(v.begin(),v.end(),a/v[i])!=v.end())
// 		{
// 			Arr[2]=min(v[i],a/v[i]);
// 			Arr[4]=max(v[i],a/v[i]);
// 		}
// 		else if(b%v[i]==0 && find(v.begin(),v.end(),b/v[i])!=v.end())
// 		{
// 			Arr[3]=min(v[i],b/v[i]);
// 			Arr[5]=max(v[i],a/v[i]);
// 		}
// 	}

// 	cout<<"! ";
// 	for(lli i=0;i<6;i++)
// 	{
// 		cout<<Arr[i]<<" ";
// 	}
// 	cout<<endl;
// }
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a,b;
	vector<lli> temp={4,8,15,16,23,42};
	lli Arr[6];
	cout<<"? "<<1<<" "<<2<<endl;
	cin>>a;
	cout.flush();
	cout<<"? "<<2<<" "<<3<<endl;
	cin>>b;
	cout.flush();
	for(lli i=0;i<6;i++)
	{
		if(a%temp[i]==0 && b%temp[i]==0 && find(temp.begin(),temp.end(),a/temp[i])!=temp.end() && find(temp.begin(),temp.end(),b/temp[i])!=temp.end())
		{
			Arr[1]=temp[i];
			Arr[0]=a/temp[i];
			Arr[2]=b/temp[i];
		}
	}

	cout<<"? "<<4<<" "<<5<<endl;
	cin>>a;
	cout.flush();
	cout<<"? "<<5<<" "<<6<<endl;
	cin>>b;
	cout.flush();
	for(lli i=0;i<6;i++)
	{
		if(a%temp[i]==0 && b%temp[i]==0 && find(temp.begin(),temp.end(),a/temp[i])!=temp.end() && find(temp.begin(),temp.end(),b/temp[i])!=temp.end())
		{
			Arr[4]=temp[i];
			Arr[3]=a/temp[i];
			Arr[5]=b/temp[i];
		}
	}
	cout<<"! ";
	for(lli i=0;i<6;i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}