    #include<iostream>
    #include<bits/stdc++.h>
     
    using namespace std;
    typedef long long int lli;
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	lli T;
    	cin>>T;
    	lli Arr[26][100005];     //Array for storing frequency of characters

    	lli IND[26];             //Array to store latest index of that haracter
    	while(T--)
    	{
    		lli N;
    		cin>>N;
    		string s;
    		cin>>s;
    		memset(Arr,0,sizeof(Arr));
    		vector<lli> v[N+1];             //store what all values have occurded till this index
    		vector<lli> prev[N+1];          //store the previous i for same character
    		// v.clear();
    		// prev.clear();
    		Arr[s[0]-'a'][1]++;
    		v[1].push_back(s[0]-'a');
    		prev[1].push_back(1);
    		memset(IND,0,sizeof(IND));
    		IND[s[0]-'a']=1;
    		lli maxi=3;
    		for(lli i=2;i<=N;i++)
    		{

    			for(lli j=0;j<25;j++)
    			{
    				Arr[j][i]=Arr[j][i-1];
    			}

    			Arr[s[i-1]-'a'][i]=Arr[s[i-1]-'a'][i-1]+1;
    			if(Arr[s[i-1]-'a'][i]==1 && Arr[s[i-1]-'a'][i-1]==0 )
    			{
    				prev[i].push_back(i);
    				IND[s[i-1]-'a']=i;
    			}
    			else
    			{
    				lli p=IND[s[i-1]-'a'];
    				lli siz=prev[p].size();
    				for(lli j=0;j<siz;j++)
    				{
    					prev[i].push_back(prev[p][j]);
    				}
    				prev[i].push_back(i);
    				IND[s[i-1]-'a']=i;
    			}	
    			for(lli j=0;j<25;j++)
    			{		
    				if(Arr[j][i]!=0)
    				{
    					v[i].push_back(j);
    				}
    			}
    		}
    			for(lli i=1;i<=N;i++)
    			{
    				lli siz=prev[i].size();
    				for(lli c=0;c<siz;c++)
    				{
    					lli j=prev[i][c];
    					lli x=v[i].size();
    					for(lli k=0;k<x;k++)
    					{
    						lli t=v[i][k];
    						{
    							if(i-j+1<= 2*(Arr[t][i]-Arr[t][j-1])+1)
	    					    {
	    					        if(maxi<2*(Arr[t][i]-Arr[t][j-1])+1)
	    					        {
	    					            maxi=2*(Arr[t][i]-Arr[t][j-1])+1;
	    					        }
	    					    }
    						}
    					    
    				
    						//cout<<i<<" "<<j<<" "<<maxi<<endl;	
    					}
    				}
    			}
    			if(maxi>=N)
    			    cout<<N<<endl;
    			else
    			    cout<<maxi<<endl;
    		
    	}
    		
    }