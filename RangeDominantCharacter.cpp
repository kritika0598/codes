
int BIT[26][100005];
int MAX=100001;

void update(int indx,int val,int x)
{
    while(indx<=MAX)
    {
        BIT[x][indx]+=val;
        indx+=(indx&(-indx));
    }
}

int query(int indx, int x)
{
    int res=0;
    while(indx>0)
    {
        res+=BIT[x][indx];
        indx-=(indx&(-indx));
    }
    return res;
}

vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    memset(BIT,0,sizeof(BIT));
    for(int i=0;i<A.length();i++)
    {
        update(i+1,1,A[i]-'a');
    }
    
    vector<int> ans;
    for(int i=0;i<B.size();i++)
    {
        int maxi=0;
        int cnt=0;
        for(int j=0;j<=25;j++)
        {
            int x=query(B[i][0]-1,j);
            int y=query(B[i][1],j);
            if(y-x>maxi)
            {
                maxi=y-x;
                cnt=1;
            }
            else if(y-x==maxi)
            {
                cnt++;
            }
        }
        ans.push_back(cnt);
        
    }
    return ans;
    
}
