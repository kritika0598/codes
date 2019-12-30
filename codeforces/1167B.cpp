#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef int lli;

int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root.
    {
     i = Arr[ i ];
    }
    return i;
}

/*modified union function where we connect the elements by changing the root of one of the element */

int union1(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B); 
    if(root_A<root_B) 
    	Arr[root_B]=root_A;
    else
    	Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N,M;
	cin>>N>>M;
	lli Arr[N+1];
	for(lli i=1;i<=N;i++)
	{
		Arr[i]=i;
	}

	for(lli i=0;i<M;i++)
	{
		lli x;
		cin>>x;
		if(x!=0)
		{
			lli a;
			cin>>a;
			for(lli i=1;i<x;i++)
			{
				lli b;
				cin>>b;
				union1(Arr,a,b);
				a=b;
			}
		}
		
	}

	for(lli i=1;i<=N;i++)
	{
		Arr[i]=root(Arr,i);	
		//cout<<Arr[i]<<" ";
	}
	//cout<<endl;
	map<lli,lli> m;
	for(lli i=1;i<=N;i++)
	{
		m[Arr[i]]++;
	}

	for(lli i=1;i<=N;i++)
	{
		cout<<m[Arr[i]]<<" ";
	}
	cout<<endl;

}