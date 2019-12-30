#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--)
	{
		lli n;
		cin>>n;
		lli Arr[n][6];
		for(lli i=0;i<n;i++)
		{
			for(lli j=0;j<6;j++)
			{
				cin>>Arr[i][j];
			}
		}
		lli x[n][2],y[n][2];
		lli minx=100000,maxx=-100000;
		lli miny=100000,maxy=-100000;
		for(lli i=0;i<n;i++)
		{
			if(Arr[i][0]<minx)
			{
				minx=Arr[i][0];
			}
			if(Arr[i][0]>maxx)
			{
				maxx=Arr[i][0];
			}
			if(Arr[i][1]<miny)
			{
				miny=Arr[i][1];
			}
			if(Arr[i][1]>maxy)
			{
				maxy=Arr[i][1];
			}
		}

		for(lli i=0;i<n;i++)
		{
			if(Arr[i][2]==1)
			{
				x[i][0]=minx;
			}
			else
			{
				x[i][0]=Arr[i][0];
			}
			if(Arr[i][4]==1)
			{
				x[i][1]=maxx;
			}
			else
			{
				x[i][1]=Arr[i][0];
			}
			if(Arr[i][3]==1)
			{
				y[i][1]=maxy;
			}
			else
			{
				y[i][1]=Arr[i][1];
			}
			if(Arr[i][5]==1)
			{
				y[i][0]=miny;
			}
			else
			{
				y[i][0]=Arr[i][1];
			}
		}


		lli ans1=x[0][0],ans2=x[0][1];
		lli a1=y[0][0],a2=y[0][1];
		bool flag=true;
		for(lli i=1;i<n;i++)
		{
			if(x[i][0]>ans2 || x[i][1]<ans1 || y[i][0]>a2 || y[i][1]<a1)
			{
				cout<<0<<endl;
				flag=false;
				break;
			}
			else
			{
				if(x[i][0]>ans1)
				{
					ans1=x[i][0];
				}
				if(x[i][1]<ans2)
				{
					ans2=x[i][0];
				}
				if(y[i][0]>a1)
				{
					a1=y[i][0];
				}
				if(y[i][1]<a2)
				{
					a2=y[i][0];
				}
			}
			if(ans1 > ans2 || a1 > a2) 
			{
		        cout << "0\n";
		        flag=false;
		        break;
    		}
		}
		
		if(!flag)
		{
			continue;
		}
		else
		{
			cout<<1<<" "<<ans1<<" "<<a1<<endl;
		}

	}	
}