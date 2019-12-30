#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	lli a,b,c;
	cin>>a>>b>>c;

	lli x=min(a/3,min(b/2,c/2));

	a-=x*3;
	b-=x*2;
	c-=x*2;
	//cout<<x<<endl;
	lli ans=x*7;
	//cout<<ans<<endl;
	if(ans==0)
		ans++;
	lli bbb=ans;
	lli a1;
	//cout<<ans<<endl;
	//if(a==0)
	{
		a1=ans;
		if(a>=2 && b>=2 && c>=2)
			a1+=6;
		else if(a>=1 && b>=2 && c>=2)
			a1+=5;
		
		if(a>=2 && b>=1 && c>=1)
			a1+=4;
		else if(a>=1 && b>=1 && c>=1)
			a1+=3;
		else if(a>=1 && b>=1)
			a1+=2;
		else if(a>=1 && c>=1)
			a1+=2;
		else if(b>=1)
			a1++;
		else if(c>=1)
			a1++;


		bbb=max(a1,bbb);
	}
	//if(b==0)
//	cout<<bbb<<endl;
	{
		a1=ans;
		if(a>=1 && c>=2 && b>=1)
			a1+=4;
		else if(a>=1 && c>=2)
			a1+=3;
		else if(a>=2 && b>=1)
			a1+=3;
		else if(a>=2)
			a1+=2;
		else if(a>=1 && c>=1)
			a1+=2;
		else if(a>=1)
			a1++;
		else if(c>=1)
			a1++;
		bbb=max(bbb,a1);
	}
	//if(c==0)
//	cout<<bbb<<endl;
	{
		a1=ans;
		if(b>=2 && a>=2 && c>=1)
			a1+=5;
		else if(b>=2 && a>=2)
			a1+=4;
		else if(a>=2 && b==1)
			a1+=3;
		else if(a>=1 && b>=1)
			a1+=2;
		else if(a>=1 && c>=1)
			a1+=2;
		else if(a>=1 || b>=1)
			a1++;
		bbb=max(bbb,a1);
	}

	cout<<bbb<<endl;
			
}