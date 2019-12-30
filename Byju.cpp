#include<bits/stdc++.h>
using namespace std;

int Arr[505][505];
int row[]={-1,1,0,0};
int col[]={0,0,-1,1};
int N,M;
bool visited[505][505];
set<pair<int,int>> st;

void bfs(int i, int j,int act)
{
    //st.erase(st.begin());
    visited[i][j]=true;
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(i,j),0));
    while(!q.empty())
    {
        pair<pair<int,int>,int>f=q.front();
        q.pop();
        int dis=f.second;
        int x=f.first.first;
        int y=f.first.second;
    //  int act=f.second;
        if((abs(x-i)+abs(y-j))>act)
            continue;
        if(dis==act && (abs(x-i)+abs(y-j)==act))
        {
            if(Arr[x][y]>Arr[i][j]+1)
            {
                Arr[x][y]=Arr[i][j]+1;
              //  if(!visited[x][y])
                    st.insert({x,y});
            }
            continue;
        }
        for(int in=0;in<4;in++)
        {

            if(x+row[in]>=0&&x+row[in]<N&&y+col[in]>=0&&y+col[in]<M )
            {
                if(dis+1<=act && abs(row[in])+abs(col[in])<=act )
                    q.push(make_pair(make_pair(x+row[in],y+col[in]),dis+1));
            }
        }
    }    
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        cin >> N;
        cin >> M;
        int A[N][M];
        for (int i_A=0; i_A<N; i_A++)
        {
            for(int j_A=0; j_A<M; j_A++)
            {
                cin >> A[i_A][j_A];
                Arr[i_A][j_A]=1000006;
            }
        }
        memset(visited,false,sizeof(visited));
        int sx;
        cin >> sx;
        int sy;
        cin >> sy;
        st.insert({sx-1,sy-1});
        Arr[sx-1][sy-1]=0;
      //  visited[sx-1][sy-1]=true;
        while(!st.empty())
        {
            pair<int,int> f=*st.begin();
            st.erase(st.begin());
            bfs(f.first,f.second,A[f.first][f.second]);
             //
            cout<<f.first<<" "<<f.second<<endl;
            for (int i_A=0; i_A<N; i_A++)
            {
             for(int j_A=0; j_A<M; j_A++)
             {
                 cout<<Arr[i_A][j_A]<<" ";
             }
             cout<<endl;
            }
            cout<<endl;
            cout<<endl;
             for (int i_A=0; i_A<N; i_A++)
            {
             for(int j_A=0; j_A<M; j_A++)
             {
                 cout<<visited[i_A][j_A]<<" ";
             }
             cout<<endl;
            }
            
        }
        
        int Q;
        cin >> Q;
        vector<int> x(Q);
        vector<int> y(Q);

        for(int i=0; i<Q; i++)
        {
            cin >> x[i]>>y[i];
            if(Arr[x[i]-1][y[i]-1]>=1000006)
            {
                cout<<-1<<endl;
            }
            else
                cout<<Arr[x[i]-1][y[i]-1]<<endl;
         }
         
         x.clear();
         y.clear();
         memset(Arr,0,sizeof(Arr));
         st.clear();
         
         
    }
}