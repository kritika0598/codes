/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
    int N, M;
    cin>>N;
    cin>>M;
    lli data[N][M];
    bool flag=false;
    lli x;
    map<lli,vector<lli>> mar;
    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin>>x;
            mar[x].push_back(i);
            if(mar[x].size()>2)
            {
                flag=true;
            }
        }
    }
    
    if(flag==false)
    {
        cout<<0<<endl;
        return 0;
    }
    
    map<lli,vector<lli>> :: iterator itr;
    lli maxi=0;
    for(itr=mar.begin();itr!=mar.end();itr++)
    {
        vector<lli> temp=itr->second;
        if(temp.size()>maxi)
        {
            maxi=temp.size();
        }
    }
    if(maxi==4)
    {
        
        cout<<2<<endl;
    }
    else if(maxi==3)
    {
        //
        set<lli> st;
        for(itr=mar.begin();itr!=mar.end();itr++)
        {
            vector<lli> temp=itr->second;
            if(temp.size()==maxi)
            {
                for(lli i=0;i<maxi;i++)
                {
                    st.insert(temp[i]);
                }
            }
        }
        if(st.size()==3)
        {
            cout<<1<<endl;
        }
        else if(st.size()== 4)
        {
            map<vector<lli>,lli> z;
            lli pt=0;
            for(itr=mar.begin();itr!=mar.end();itr++)
            {
                vector<lli> temp=itr->second;
                if(temp.size()==maxi)
                {
                    z[temp]++;
                    pt=max(z[temp],pt);
                }
            }
            
            if(pt>=2)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
        else
        {
            cout<<2<<endl;
        }
        //cout<<1<<endl;
    }
    else
    {
        cout<<3<<endl;
    }
    // process the inputs here
    // and print the output
    
	return 0;
}