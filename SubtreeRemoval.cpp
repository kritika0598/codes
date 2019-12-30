#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli summ[100005];
		
int fun(lli parent[],  vector<lli> v[], lli node, lli Arr[])
{
	if(v[node].size()==0)
		return summ[node]=Arr[node];
	summ[node]=Arr[node];
	for(lli i=0;i<v[node].size();i++)
	{
		summ[node]+=fun(parent,v,v[node][i], Arr);
	}
	return summ[node];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	while(T--)
	{
		lli N,X;
		cin>>N>>X;
		lli Arr[N+1];
		vector<lli> v[N+1];
		lli p[2][N+1];
		lli parent[N+1];
		memset(summ,0,sizeof(summ));
		for(lli i=1;i<=N;i++)
		{
			cin>>Arr[i];
		}
		for(lli i=0;i<N-1;i++)
		{
			lli x,y;
			cin>>x>>y;
			v[x].push_back(y);
		//	v[y].push_back(x);
			parent[y]=x;
		}

		lli ans=fun(parent,v,1,Arr);

		// for(lli i=1;i<=N;i++)
		// {
		// 	cout<<summ[i]<<" ";
		// }
		// cout<<endl;
	//	cout<<ans<<endl;
		// if(ans<=0)
		// {
		// 	cout<<"Hello"<<endl;
		// 	cout<<X*(-1)<<endl;			
		// }
		//else
		{
			lli k=0;
			for(lli i=2;i<=N;i++)
			{
				if(summ[i]<0)
				{
					p[0][k]=summ[i];
					p[1][k]=i;
					k++;
				}
			}
			lli ab=ans;
			if(k!=0)
			{
				for(lli i=0;i<k;i++)
				{
					if(binary_search(p[1],p[1]+k, parent[p[1][i]]))
					{
						//cout<<p[1][i]<<endl;
						//p[1][i]=-1;
						p[0][i]=0;
					}
				}
				vector<lli> c;
				for(lli i=0;i<k;i++)
				{
					if(p[0][i]!=0)
					{
						c.push_back(p[0][i]);
					}
				}
				sort(c.begin(),c.end());
				lli bb[c.size()];
				bb[0]=c[0]*(-1);
				ab=max(ab, (ans+bb[0])-X);
				//cout<<ab<<" ";
				for(lli i=1;i<c.size();i++)
				{
					bb[i]=bb[i-1]+((-1)*c[i]);
					ab=max(ab, (ans+bb[i])-(X*(i+1)));
					//cout<<ab<<" ";
				}
				//cout<<endl;

			}
			
			cout<<ab<<endl;


		}


		

	}
}