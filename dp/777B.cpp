#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef  long long int ll;
using namespace std;



            int main()
            {
                ll n,i,ans=0,ans1=0,j;
                string s,m;

                cin>>n;

                cin>>s>>m;

                sort(s.begin(),s.end());
                sort(m.begin(),m.end());

                for(i=0,j=0;j<n;)
                {
                    if(m[j]>=s[i])
                        {

                             i++;
                            j++;
                        }
                    else
                    {
                        ans++;
                        j++;
                    }
                }

                 for(i=0,j=0;j<n;)
                {
                    if(s[i]<m[j])
                        {
                            ans1++;
                            j++;
                            i++;
                        }

                        else
                        {
                            j++;
                        }
                }

                cout<<ans<<endl<<ans1<<endl;

            }		
