#include<bits/stdc++.h>

using namespace std;
int L[2][1005];

int LCS(int a[],int b[],int m, int n)
{
    int i,j;

    bool bi;

    for(i=0; i<=m; i++)
    {
        bi=i&1;
        for(j=0; j<=n; j++)
        {
            if(i==0||j==0)
                L[bi][j]=0;
            else if(a[i-1]==b[j-1])
                L[bi][j]=L[1-bi][j-1]+1;
            else
                L[bi][j]=max(L[1-bi][j],L[bi][j-1]);
        }
    }
    return L[bi][n];
}
int main()
{
    int d;

    cin>>d;

    while(d--)
    {
        int a[1005],n,m,i;

        for(i=0; i<1005; i++)
        {
            cin>>a[i];
            n=i;
            if(a[i]==0)
                i=1005;
        }
        int t=1,Max=0;
        while(1)
        {
            int T[1005],Q;
            for(i=0; i<1005; i++)
            {
                cin>>T[i];
                m=i;
                if(T[i]==0)
                    i=1005;
            }
            if(T[0]==0)
                break;
            else
                Q=LCS(a,T,n,m);

            Max=max(Max,Q);
        }
        cout<<Max<<"\n";
    }


}