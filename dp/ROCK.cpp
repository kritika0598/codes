// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// typedef long long int lli;

// int m[201][201];
// lli Arr[201];
// lli cum0[201];
// lli cum1[201];
// lli N;

// int MatrixChainOrder( int i, int j) 
// { 
// 	if(i==j)
// 	{
// 		if(Arr[i]==1)
// 			return m[i][j]=1;
// 		else
// 			return m[i][j]=0;
// 	}

//     if(m[i][j]!=-1)
//         return m[i][j];
//     int k; 
//     int min = INT_MIN; 
//     int count; 
  
//     // place parenthesis at different places between first 
//     // and last matrix, recursively calculate count of 
//     // multiplications for each parenthesis placement and 
//     // return the minimum count 


//     if(i!=0)
// 	{
// 		if((cum1[j]-cum1[i-1])>(cum0[j]-cum0[i-1]))
// 		{
// 			return m[i][j]=j-i+1;
// 		}
// 		else
// 		{

// 			for(lli k=i;k<=j-1;k++)
// 			{
// 				lli count = MatrixChainOrder(i, k) + MatrixChainOrder(k+1, j); 
//  				if (count > min) 
//             		min = count;
// 			}
// 			return m[i][j]=min;
// 		}
// 	}
// 	else
// 	{
// 		if((cum1[j])>(cum0[j]))
// 		{
// 			return m[i][j]=j-i+1;
// 		}
// 		else
// 		{
// 			for(lli k=i;k<=j-1;k++)
// 			{
// 				lli count = MatrixChainOrder(i, k) + MatrixChainOrder(k+1, j); 
//  				if (count > min) 
//             		min = count;
// 			}
// 			return m[i][j]=min;
// 		}
// 	}

// } 



// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	lli T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		//lli N;
// 		cin>>N;
// 		for(lli i=0;i<N;i++)
// 		{
// 			for(lli j=0;j<N;j++)
// 			{
// 				m[i][j]=-1;
// 			}
// 		}
// 		string s;
// 		cin>>s;
// 		memset(Arr,0,sizeof(Arr));
// 		memset(cum0,0,sizeof(cum0));
// 		memset(cum1,0,sizeof(cum1));
// 		for(lli i=0;i<N;i++)
// 		{
// 			Arr[i]=s[i]-'0';
// 		}
// 		if(Arr[0]==0)
// 		{
// 			cum0[0]=1;
// 			cum1[0]=0;
// 		}
// 		else
// 		{
// 			cum1[0]=1;
// 			cum0[0]=0;
// 		}

// 		for(lli i=1;i<N;i++)
// 		{
// 			if(Arr[i]==0)
// 			{
// 				cum1[i]=cum1[i-1];
// 				cum0[i]=cum0[i-1]+1;
// 			}
// 			else
// 			{
// 				cum1[i]=cum1[i-1]+1;
// 				cum0[i]=cum0[i-1];
// 			}
// 		}

// 		cout<<MatrixChainOrder(0, N-1)<<endl;
// 		// for(lli i=0;i<N;i++)
// 		// {
// 		// 	for(lli j=0;j<N;j++)
// 		// 	{
// 		// 		cout<<m[i][j]<<" ";
// 		// 	}
// 		// 	cout<<endl;
// 		// }
// 		// cout<<endl;

// 		//cout<<m[0][N-1]<<endl;


// 	}
		
// }

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
	while(T--)
	{
		lli N;
		cin>>N;
		string s;
		cin>>s;
		lli cum1[N];
		lli cum0[N];
		if(s[0]=='0')
		{
			cum0[0]=1;
			cum1[0]=0;
		}	
		else
		{
			cum0[0]=0;
			cum1[0]=1;
		}	
		for(lli i=1;i<N;i++)
		{
			if(s[i]=='0')
			{
				cum1[i]=cum1[i-1];
				cum0[i]=cum0[i-1]+1;
			}
			else
			{
				cum1[i]=cum1[i-1]+1;
				cum0[i]=cum0[i-1];
			}
		}

		lli b[N];
		b[0]=s[0]-'0';                 //b stores the maximum possible length upto i
		for(lli i=1;i<N;i++)
		{
			b[i]=b[i-1];
			for(lli j=i-1;j>=0;j--)
			{
				if(j==0)
				{
					if(cum1[i]>cum0[i])
					{
						if(j==0)
						{
							b[i]=max(b[i],i-j+1+b[0]);
						}
						else
						{
							b[i]=max(b[i],i-j+1+b[j-1]);
						}
					}
				}
				else
				{
					if(cum1[i]-cum1[j-1]>cum0[i]-cum0[j-1])           //interval between j to i
					{
						if(j==0)
						{
							b[i]=max(b[i],i-j+1+b[0]);
						}
						else
						{
							b[i]=max(b[i],i-j+1+b[j-1]);
						}
					}
				}
				
			}
		}

		cout<<b[N-1]<<endl;
	}		
}