#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
    int n,k;
	cin >> n >> k;
	int turn = 1;
	bool flag = false;
	if(n<=k)
		cout<<"First"<<endl;
	else
	{
		while(n>k)
		{
			n=n-(k+1);
		}
		if(n>0)
			cout<<"First"<<endl;
		else
			cout<<"Second"<<endl;	
	}
	
}