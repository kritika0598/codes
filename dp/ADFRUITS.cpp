#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

void showstack(stack <lli> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout <<endl; 
} 

char s1[105];
char s2[105];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(scanf("%s",s1)!=EOF)
	{
		scanf("%s",s2);
		lli N = strlen(s1);
		lli M = strlen(s2);
		//lli N=s1.length();
		//lli M=s2.length();
		lli DP[N+1][M+1];
		stack<lli>a1;
		stack<lli>a2;
		memset(DP,0,sizeof(DP));
		// while(!a1.empty())
		// {
		// 	a1.pop();
		// }
		// while(!a2.empty())
		// {
		// 	a2.pop();
		// }
		for(lli i=0;i<=N;i++)
		{
			DP[0][i]=0;
		}

		for(lli i=0;i<=M;i++)
		{
			DP[i][0]=0;
		}

		for(lli i=1;i<=N;i++)
		{
			for(lli j=1;j<=M;j++)
			{
				if(s1[i-1]==s2[j-1])
				{
					DP[i][j]=DP[i-1][j-1]+1;
				}
				else
				{
					if(DP[i][j-1]>DP[i-1][j])
						DP[i][j]=DP[i][j-1];
					else
						DP[i][j]=DP[i-1][j];
				}
			}
		}

		string a="";

		lli i=N,j=M;
		lli st1,st2,e1,e2;
		bool flag=true;
		while(1)
		{
			if(s1[i-1]==s2[j-1])
			{
				a=a+s1[i-1];
				// if(flag)
				// {

				// 	e1=i-1;
				// 	e2=j-1;
				// 	flag=false;
				// }
				a1.push(i-1);
				a2.push(j-1);
				// st1=i-1;
				// st2=j-1;
				i=i-1;
				j=j-1;
			}
			else
			{
				if(DP[i][j-1]>DP[i-1][j])
				{
					i=i;
					j=j-1;
				}
				else
				{
					i=i-1;
					j=j;
				}
			}

			if(i==0 || j==0)
			{
				break;
			}

		}
		// showstack(a1);
		// showstack(a2);
		lli x=a.length();
		string b="";
		for(i=x-1;i>=0;i--)
		{
			b=b+a[i];
		}

		//cout<<b<<endl;
		//cout<<st1<<" "<<e1<<" "<<st2<<" "<<e2<<endl; 
		string z="";
		if(b.length()==N)
		{
			cout<<s2<<endl;
		}
		else if(b.length()==M)
		{
			cout<<s1<<endl;
		}
		else
		{
			lli x1=0;
			lli y1=0;
			while(!a1.empty() || !a2.empty())
			{
				lli x2=a1.top();
				lli y2=a2.top();
				a1.pop();
				a2.pop();
				for(i=x1;i<x2;i++)
				{
					z=z+s1[i];
				}
				for(i=y1;i<y2;i++)
				{
					z=z+s2[i];
				}
				z=z+s1[x2];
				x1=x2+1;
				y1=y2+1;
			}
			for(i=x1;i<N;i++)
			{
				z=z+s1[i];
			}
			for(i=y1;i<M;i++)
			{
				z=z+s2[i];
			}

			cout<<z<<endl;
		}

	}
		
}