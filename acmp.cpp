#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int x[3];
		int y[3];
		int z[3];
		int rank[3][3];
		memset(rank,-1,sizeof(rank));
		for(int i=0;i<3;i++)
		{
			cin>>x[i];
			cin>>y[i];
			cin>>z[i];
		}
		int maxi = -1;
		for(int i=0;i<3;i++){
			if(x[i] > x[ (i+1) % 3] && x[i] > x[ (i+2) % 3 ]){
				maxi = i;
				break;
			}
			if(y[i] > y[ (i+1) % 3] && y[i] > y[ (i+2) % 3 ]){
				maxi = i;
				break;
			}
			if(z[i] > z[ (i+1) % 3] && z[i] > z[ (i+2) % 3 ]){
				maxi = i;
				break;
			}
		}


		for(int i=0;i<3;i++)
		{

			if(x[i%3]>=x[(i+1)%3] && x[(i)%3]>=x[(i+2)%3])
			{
				if(x[i%3]==x[(i+1)%3])
					rank[0][0]=maxi;
				else
					rank[0][0]=i%3;
				if(x[i%3]==x[(i+2)%3])
					rank[0][0]=maxi;
				else
					rank[0][0]=i%3;
				if(x[(i+1)%3]>=x[(i+2)%3])
				{
					if(x[(i+1)%3]==x[(i+2)%3])
					{
						rank[0][1]=min((i+1)%3,(i+2)%3);
						rank[0][2]=max((i+1)%3,(i+2)%3);
					}
					else
					{
						rank[0][1]=(i+1)%3;
						rank[0][2]=(i+2)%3;
					}	
				}	
				else
				{
					rank[0][1]=(i+2)%3;
					rank[0][2]=(i+1)%3;
				}	
	
			}	
			if(y[i%3]>=y[(i+1)%3] && y[(i)%3]>=y[(i+2)%3])
			{
				if(y[i%3]==y[(i+1)%3])
					rank[1][0]=maxi;
				else
					rank[1][0]=i%3;
				if(y[i%3]==y[(i+2)%3])
					rank[1][0]=maxi;
				else
					rank[1][0]=i%3;
				if(y[(i+1)%3]>=y[(i+2)%3])
				{
					if(y[(i+1)%3]==y[(i+2)%3])
					{
						rank[1][1]=min((i+1)%3,(i+2)%3);
						rank[1][2]=max((i+1)%3,(i+2)%3);
					}
					else
					{
						rank[1][1]=(i+1)%3;
						rank[1][2]=(i+2)%3;
					}	
				}	
				else
				{
					rank[1][1]=(i+2)%3;
					rank[1][2]=(i+1)%3;
				}	
			}	
			if(z[i%3]>=z[(i+1)%3] && z[(i)%3]>=z[(i+2)%3])
			{
				if(z[i%3]==z[(i+1)%3])
					rank[2][0]=maxi;
				else
					rank[2][0]=i%3;
				if(z[i%3]==z[(i+2)%3])
					rank[2][0]=maxi;
				else
					rank[2][0]=i%3;
				if(z[(i+1)%3]>=z[(i+2)%3])
				{
					if(z[(i+1)%3]==z[(i+2)%3])
					{
						rank[2][1]=min((i+1)%3,(i+2)%3);
						rank[2][2]=max((i+1)%3,(i+2)%3);
					}
					else
					{
						rank[2][1]=(i+1)%3;
						rank[2][2]=(i+2)%3;
					}	
				}	
				else
				{
					rank[2][1]=(i+2)%3;
					rank[2][2]=(i+1)%3;
				}					

			}

			/*for(int i=0;i<3;i++)
			{
				cout<<rank[i][0]<<" "<<rank[i][1]<<" "<<rank[i][2]<<endl;
			}*/
		}

		if(rank[0][0]==rank[1][0] && rank[1][0]==rank[2][0] && rank[0][1]==rank[1][1] && rank[1][1]==rank[2][1] && rank[0][2]==rank[1][2] && rank[1][2]==rank[2][2])
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
		/*for(int i=0;i<3;i++)
		{
			cout<<rank[i][0]<<" "<<rank[i][1]<<" "<<rank[i][2]<<endl;
		}*/
		

	}
	
}