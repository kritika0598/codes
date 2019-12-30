    #include<iostream>
    #include<bits/stdc++.h>
     
    using namespace std;
    typedef long long int lli;
    lli Tree[1000005];
    lli Lazy[1000005];
     
    void update1(lli Node, lli start, lli end, lli l, lli r, lli val)
    {
    	
    	if(Lazy[Node]!=0)
    	{
    		Tree[Node]=Tree[Node]+((end-start+1)*Lazy[Node]);
    		if(start!=end)
    		{
    			Lazy[2*Node]=Lazy[2*Node]+Lazy[Node];
    			Lazy[2*Node+1]=Lazy[2*Node+1]+Lazy[Node];
    		}
    		Lazy[Node]=0;
    	}
     
    	if(start>end || start>r || end<l )
    		return;
    	//else
    	{
    		if(start>=l && end<=r)
    		{
    			Tree[Node]+=(end-start+1)*val;
    			if(start!=end)
    			{
    				Lazy[2*Node]+=val;
    				Lazy[2*Node+1]+=val;
    			}
    			return;
    		}
    		//else
    		{
    			lli mid=(start+end)/2;
    			update1(2*Node,start,mid,l,r,val);
    			update1(2*Node+1,mid+1,end,l,r,val);
    			Tree[Node]=Tree[2*Node]+Tree[2*Node+1];
    		}
    	}
    }
     
    lli query1(lli Node, lli start, lli end, lli l, lli r)
    {
    	if(start>end   || start>r || end<l)
    		return 0;
    	if(Lazy[Node]!=0)
    	{
    		Tree[Node]=Tree[Node]+(end-start+1)*Lazy[Node];
    		if(start!=end)
    		{
    			Lazy[2*Node]=Lazy[2*Node]+Lazy[Node];
    			Lazy[2*Node+1]=Lazy[2*Node+1]+Lazy[Node];
    		}
    		Lazy[Node]=0;
    	}
    	//else
    	{
    		if(start>=l && end<=r)
    		{
    			return Tree[Node];
    		}
    		//else
    		{
    			lli mid= (start+end)/2;
    			lli p=query1(2*Node,start,mid,l,r);
    			lli q=query1(2*Node+1,mid+1,end,l,r);
    			return (p+q);
    		}
    	}
    }
     
     
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	lli T;
    	cin>>T;
    	while(T--)
    	{
    		lli N;
    		cin>>N;
    		lli C;
    		cin>>C;
    		//lli Tree[2*N];
    		//lli Lazy[2*N];
    		memset(Tree,0,sizeof(Tree));
    		memset(Lazy,0,sizeof(Lazy));
    		while(C--)
    		{
    			lli type;
    			cin>>type;
    			if(type==0)
    			{
    				lli l,r,v;
    				cin>>l>>r>>v;
    				update1(1,1,N,l,r,v);
    				// for(lli i=1;i<=(2*N-1);i++)
    				// {
    				// 	cout<<Tree[i]<<" ";
    				// }
    				// cout<<endl;
    				// for(lli i=1;i<=(2*N-1);i++)
    				// {
    				// 	cout<<Lazy[i]<<" ";
    				// }
    				// cout<<endl;
    			}
    			else
    			{
    				lli l,r;
    				cin>>l>>r;
    				lli ans=query1(1,1,N,l,r);
    				cout<<ans<<endl;
    			}
    		}
     
     
    	}
    		
    } 