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
		lli n;
		cin>>n;
		lli arr[n+1];
		bool flag=false;
		bool f=true;
		bool flag2=true;
		lli l=0;
		lli max=-1;
		lli pos;
		for(lli i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]>max)
			{
				max=arr[i];
				pos=i;
			}	
			if(arr[i]!=-1)
			{
				flag=true;
				arr[i]=arr[i]-1;
				if(!(arr[i]>arr[l] && (arr[i]-arr[l])==(i-l)))
				{
					f=false;
				}
				l=i;
			}
			//cout<<arr[i]<<endl;	
		}
		max--;
		if(!flag || f)
		{
			cout<<"inf"<<endl;
		}
		else
		{
			lli k = pos+1;
			lli ans = max;
			while(k<n && arr[k] == -1) 
			{
				ans++;
				arr1[k]=ans;
				k++;
				
			}
			lli maxi=-1;
			for(lli i=n-1;i>0;i--)
			{
				if(arr[i]>arr[i-1] && (arr[i]-arr[i-1]==1 || arr[i-1]==-1))
				{
					arr[i-1]=arr[i]-1;
				}
				else if(arr[i]>=arr[i-1] && (arr[i]-arr[i-1]!=1) && arr[i]!=-1)
				{
					cout<<"impossible"<<endl;
					flag2=false;
					break;
				}
				else if(arr[i]!=-1)
				{
						
					if(arr[i]==0 && arr[i-1]==-1)
					{
						lli m=i-1;
						lli p=0;
						while(arr[m]==-1)
						{
							p++;
							m--;
						}
						for(lli j=m+1;j<i;j++)
						{
							arr[j]=arr[j-1]+1;
							cout<<j<<"jhkdh "<<arr[j]<<endl;
						}
						if((arr[m]+p)<max)
						{
							cout<<"impossible"<<endl;
							flag2=false;
							break;
						}
						else
						{
							max=arr[m]+p;
						}	
					}
					else if(arr[i]==0 && arr[i-1]<max)
					{
						cout<<"impossible"<<endl;
						flag2=false;
						break;
					}
				}
				else if(arr[i]==-1)
				{

						lli m=i-1;
						lli p=0;
						while(arr[m]==-1)
						{
							p++;
							m--;
						}
						for(lli j=m+1;j<=i;j++)
						{
							arr[j]=arr[j-1]+1;
						}
						i++;
				}
				cout<<i<<" "<<arr[i]<<endl;
			}

			cout<<arr[0]<<endl;
			//cout<<endl;

			for(lli i=0;i<n-1;i++)
			{
				if(arr[i+1]==0 && arr[i]<max && flag2)
				{
					cout<<"impossible"<<endl;
					break;
				}	
			}
			if(flag2)
				cout<<max+1<<endl;
		}
	}
		
}