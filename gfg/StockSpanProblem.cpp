#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

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
	    stack<pair<lli,lli>> st;
	    lli Arr[N];
	    lli x;
	    cin>>x;
	    st.push(make_pair(x,0));Arr[0]=1;
	    cout<<Arr[0]<<" ";
	    for(lli i=1;i<N;i++)
	    {
	        cin>>x;
	        Arr[i]=1;
	        if(!(st.empty()))
	        {
    	        while((x>st.top().first))
    	        {
    	            Arr[i]+=Arr[st.top().second];
    	            st.pop();
    	            if(st.empty())
    	            	break;
    	        }
	        }
	        st.push(make_pair(x,i));
	        cout<<Arr[i]<<" ";
	    }
	    cout<<endl;    
	}
}