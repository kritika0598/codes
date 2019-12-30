#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli N;
lli Arr[150005];
vector<lli> l[150005];
vector<lli> :: iterator itr ;
//finding root of an element.
void initialize()
{
    for(lli i =1;i<=N;i++)
    {
     	Arr[ i ] = i ;
     	l[i].push_back(i);
     }
}


int root(lli i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root.
    {
     i = Arr[ i ];
    }
    return i;
}

/*modified union function where we connect the elements by changing the root of one of the element */

void union1(lli A ,lli B)
{
    lli root_A = root( A);       
    lli root_B = root(B);
    for(itr=l[root_B].begin();itr!=l[root_B].end();itr++)
    {
    	l[root_A].push_back(*itr);
    }
    l[root_B].clear();
      
    Arr[ root_B ] = root_A ;       //setting parent of root(A) as root(B).
}
bool find(lli A,lli B)
{
    if( root(A)==root(B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	memset(Arr,0,sizeof(Arr));
	initialize();
	for(lli i=0;i<N-1;i++)
	{
		lli x,y;
		cin>>x>>y;
		union1(x,y);
	}

		for(lli i=1;i<N+1;i++)
		{
			if(l[i].size()==N)
			{
				for(itr=l[i].begin();itr!=l[i].end();itr++)
				{
					cout<<*itr<<" ";
				}
				cout<<endl;
				break;
			}
			
		}


}