#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef int lli;

lli lookup[151][151];
lli DP[151][151]; 
int count(string a, string b) 
{ 
    int m = a.length(); 
    int n = b.length(); 
  
    // Create a table to store results of sub-problems 
    int lookup[m + 1][n + 1] = { { 0 } }; 
  
    // If first string is empty 
    for (int i = 0; i <= n; ++i) 
        lookup[0][i] = 0; 
  
    // If second string is empty 
    for (int i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 
  
    // Fill lookup[][] in bottom up manner 
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            // If last characters are same, we have two  
            // options - 
            // 1. consider last characters of both strings 
            //    in solution 
            // 2. ignore last character of first string 
            if (a[i - 1] == b[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1] +  
                               lookup[i - 1][j]; 
                  
            else
                // If last character are different, ignore 
                // last character of first string 
                lookup[i][j] = lookup[i - 1][j]; 
        } 
    } 
  
    return lookup[m][n]; 
} 


lli ans=0;

lli foo(string act, vector<string> v, lli x , lli y)
{
	lli n=v.size();
	lli m=act.length();
	lli ans=0;
	if(DP[x][y]!=-1)
	{
	//	cout<<"Already p "<<x<<" "<<y<<" "<<DP[x][y]<<endl;
		return DP[x][y];
	}	
	if(x==n-1)
	{
	//	cout<<x<<" "<<y<<" "<<" "<<v[x]<<" "<<act.substr(y)<<" "<<count(v[x],act.substr(y))<<endl;
		ans= count(v[x],act.substr(y));
	}
	else
	{
		for(lli i=1;i<=(m-y)-(n-x-1);i++)
		{
				//	cout<<x<<" "<<y<<" "<<i<<" "<<" "<<v[x]<<" "<<act.substr(y,i)<<" "<<count(v[x],act.substr(y,i))<<endl;

					lli a=foo(act,v,x+1,y+i);
				//	cout<<"a "<<a<<endl;
					ans+= count(v[x],act.substr(y,i)) * a;			
		}
	}

	return DP[x][y]=ans;
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		lli N;
		cin>>N;
		if(N==0)
		{
			return 0;
		}

		string insig[N];
		for(lli i=0;i<N;i++)
		{
			cin>>insig[i];
		}

		string abvr;
		string act;
		cin>>abvr;
		act=abvr;
		while(1)
		{

			//bool foo=false;
			//while(1)
			{
				vector<string> v;
				
				if(isupper(abvr[0]))
				{
					//cout<<abvr<<endl;
					while(1)
					{
						string z;
						cin>>z;
						bool f=false;
						for(lli i=0;i<N;i++)
						{
							if(z==insig[i])
							{
								f=true;
								break;
							}	
						}
						if(isupper(z[0]))
						{
							act=abvr;
							abvr=z;
							break;
						}
						if(!f)
							v.push_back(z);
					}

				}

				if(act=="LAST" && abvr=="CASE")
				{
					break;
				}	
				for(lli i=0;i<act.length();i++)
				{
					if(isupper(act[i]))
						act[i]=tolower(act[i]);
				}
				lli count1=0;
				for(lli i=0;i<151;i++)
				{
					for(lli j=0;j<151;j++)
					{
						DP[i][j]=-1;
					}
				}
				lli xcv =foo(act, v,0,0);
				for(lli i=0;i<act.length();i++)
				{
					if(islower(act[i]))
						act[i]=toupper(act[i]);
				}
				if(xcv==0)
				{
					cout<<act<<" is not a valid abbreviation"<<endl;
				}
				else
				{
					cout<<act<<" can be formed in "<<xcv<<" ways"<<endl;
				}

			}
			
			//cout<<abvr<<endl;
		
			//cout<<abvr<<endl;
			
		}

	}
}
