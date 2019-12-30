
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
	int A[n];
	int cum[n];
	memset(cum,0,sizeof(cum));
	int Odd[n] = {0};
	memset(Odd,0,sizeof(Odd));
   	for(int i=1;i<=n;i++)
   	{
		cin >> A[i];
		if(i > 1)
		{
			if(!(i % 2))
			{
				cum[i] = cum[i-1]-A[i];
			 	Odd[i] = Odd[i-1] + A[i];
			}
			else
			{
				cum[i] = cum[i-1] + A[i];
			 	Odd[i] = Odd[i-1] - A[i];
			}
		}
		else 
		{
			cum[i] = A[i];
		 	Odd[i] = A[i];
		}
	}
	int q;
	cin >> q; 
	for(int i=0;i<q;i++){
		int l,r;
		cin >> l >> r;
		if(!(l % 2)){
			cout << Odd[r]- Odd[l-1]<<endl;
		}
		else{
			cout << cum[r]-cum[l-1]<<endl;
		}
	}
}