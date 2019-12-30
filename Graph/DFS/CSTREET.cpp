#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const long long int MAX = 1e6 + 5;
long long int id[MAX], nodes, edges;
pair <long long, pair<long long int, long long int> > p[MAX];

void initialize()
{
    for(long long int i = 0;i < MAX;++i)
        id[i] = i;
}

long long int root(long long int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(long long int x, long long int y)
{
    long long int p = root(x);
    long long int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<long long int, long long int> > p[])
{
    long long int x, y;
    long long cost, minimumCost = 0;
    for(long long int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    long long int x, y;
    long long int T;
    cin>>T;
    while(T--)
    {
    	    long long weight, cost, minimumCost,c;
		    initialize();
		    cin >>c>> nodes >> edges;
		    for(long long int i = 0;i < edges;++i)
		    {
		        cin >> x >> y >> weight;
		        p[i] = make_pair(weight, make_pair(x, y));
		    }
		    // Sort the edges in the ascending order
		    sort(p, p + edges);
		    minimumCost = kruskal(p);
		    cout << minimumCost*c << endl;
		    return 0;
    }

}