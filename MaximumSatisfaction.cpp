int Solution::solve(vector<int> &A) {
    
    int maxi=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>maxi)
        {
            maxi=A[i];
        }
    }
    
    int b=log2(maxi);
  //  cout<<b<<endl;
    vector<int> ans;
    bool f=true;
    for(int i=b;i>=0;i--)
    {
        int s=0;
        for(int j=0;j<A.size();j++)
        {
            if((A[j]&(1<<i))!=0)
            {
                ans.push_back(A[j]);
                s++;
            }
        }
        if(s>=4)
        {
            b=i;
            f=false;
            break;
        }
        else
        {
            ans.clear();
        }
    }
    if(f)
    {
        return 0;
    }
    vector<int> temp;
    int z=ans[0]&ans[1]&ans[2]&ans[3];
    for(int i=b;i>=0;i--)
    {
        int s=0;
        for(int j=0;j<ans.size();j++)
        {
            if((ans[j]&(1<<i))!=0)
            {
                temp.push_back(ans[j]);
                s++;
            }
        }
        if(s==4)
        {
            z=temp[0]&temp[1]&temp[2]&temp[3];
            return z;
        }
        else if(s>4)
        {
            z=temp[0]&temp[1]&temp[2]&temp[3];
            ans=temp;
            temp.clear();
        }
        else
        {
            temp.clear();
        }
    }
    return z;
    
}
