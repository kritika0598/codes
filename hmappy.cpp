#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,Q,K;
	cin>>N>>Q>>K;
	lli Arr[N+1];
	lli Brr[N+1];
	lli num=0;
	lli maxi=0;
	lli count=0;
	lli l=0,r=0;
	lli l1=0,r1=0,l2=0,r2=0,l4=0,r4=0,r3=0,l3=0;
	lli len1=0,len2=0,len3=0,len=0;
	lli borderu=0,borderl=N-1;

	for(lli i=0;i<N;i++)
	{
		cin>>Arr[i];
	}

	for(lli i=0;i<N;i++)
		{
			if(Arr[i]==1)
			{
				if(count==0)
				{
					l4=i;
					r4=i;
				}	
				else
					r4++;
				count++;
				if(maxi<count)
				{
					maxi=count;
					l1=l4;
					r1=r4;
				}	
			}
			else
			{
				count=0;

			}	
		}
		len1=maxi;

		count=0;
		maxi=0;

		len2=0;
		len3=0;

		for(lli i=0;i<l1;i++)
		{
			if(Arr[i]==1)
			{
				if(count==0)
				{
					l4=i;
					r4=i;
				}	
				else
					r4++;
				count++;
				if(maxi<count)
				{
					maxi=count;
					l2=l4;
					r2=r4;
				}	
			}
			else
			{
				count=0;

			}	
		}
		len2=maxi;
		maxi=0;
		count=0;
		for(lli i=r1+1;i<N;i++)
		{
			if(Arr[i]==1)
			{
				if(count==0)
				{
					l4=i;
					r4=i;
				}	
				else
					r4++;
				count++;
				if(maxi<count)
				{
					maxi=count;
					l3=l4;
					r3=r4;
				}	
			}
			else
			{
				count=0;

			}	
		}
		len3=maxi;
		if(len3>len2)
		{
			len2=len3;
			l2=l3;
			r2=r3;
		}

		//cout<<len2<<" "<<l2<<" "<<r2<<endl;

		lli C[N+1];
		C[0]=len1;

		if(Arr[0]==1 && Arr[N-1]==1)
		{
			

			lli bl=N-1,br=0;
			lli i=1;
			for(i=1;i<N;i++)
			{
				if(Arr[i]==0)
				{
					break;	
				}
			}
			br=i-1;
			for(i=N-2;i>=0;i--)
			{
				if(Arr[i]==0)
					break;
			}
			bl=i+1;
				//cout<<borderu<<endl;
				//cout<<borderl<<endl;
			len=br+1+(N-bl);


			if(l1==0 && r1==br)
			{
				l1=bl;
				r1=br;
			}
			else if(r1==N-1 && l1==bl)
			{
				l1=bl;
				r1=br;
			}

			else
			{
				if(len>len2)
				{
					len2=len;
					l2=bl;
					r2=br;
				}
			}

		}
	string s;
	cin>>s;
	
	if(C[0]==N)
	{
		for(lli i=0;i<Q;i++)
		{
			if(s[i]=='?')
			{
				if(N>K)
					cout<<K<<endl;
				else
					cout<<N<<endl;
			}
		}
		return 0;
	}

	//cout<<len2<<" "<<l2<<" "<<r2<<endl;


	for(lli i=1;i<N;i++)
	{
		//if(r>=l)
		{
			l1++;
			r1++;
			l2++;
			r2++;
			//cout<<l1<<" "<<r1<<endl;
			//cout<<l2<<" "<<r2<<endl;
			if(r2>N-1)
			{
				r2=0;
				//len2--;
			}
			if(l2>N-1)
			{
				l2=0;
			}
			if(l1>N-1)
			{
				l1=0;
			}
			if(r1>N-1)
			{
				r1=0;
			}
			if(l2>r2)
				len2=max(r2+1,N-l2);
			else
				len2=r2-l2+1;
			if(l1>r1)
				len1=max(r1+1,N-l1);
			else
				len1=r1-l1+1;
			
			//cout<<l1<<" "<<r1<<endl;
			//cout<<l2<<" "<<r2<<endl;

			//cout<<len1<<" "<<len2<<endl;
			C[i]=max(len1,len2);

	

		}
		//cout<<C[i]<<endl;
		//cout<<endl;
		
		//C[i]=len1;
	}

	//lli maxu=0;
	//lli temp;


	lli cn=0;
	//cout<<s.length()<<endl;
	for(lli i=0;i<Q;i++)
	{
		//lli cnt=0;
		//maxu=0;
		if(s[i]=='?')
		{
			if(C[cn]>K)
				cout<<K<<endl;
			else
				cout<<C[cn]<<endl;

		}
		else
		{
			cn++;
			if(cn>=N)
				cn=0;
		}
	}
		
}