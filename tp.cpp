vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    
    int n = A.length();
    int dp[26][n];
    vector<int> ans;
    memset(dp,0,sizeof(dp));
     dp[A[0]-'a'][0]=1;
    for(int i=1;i<n;i++)
    {
        
       for(int j=0;j<26;j++)
       {
           dp[j][i] = dp[j][i-1];
       }
        dp[A[i]-'a'][i]++;
    }
    
    for(int i=0;i<B.size();i++)
    {
        int l = B[i][0]-1;
        int r = B[i][1]-1;
        int mx =0;
        vector<int> v(26,0);
       
        for(int i=0;i<26;i++)
        {
            if(l==0)
                 v[i] = dp[i][r];
            else
                v[i]=dp[i][r]-dp[i][l-1];
           
            mx = max(mx,v[i]);
        }
        int c=0;
        for(int i=0;i<26;i++)
        {
            if(mx==v[i])
                c++;
        }
        ans.push_back(c);
    }
   return ans; 
}