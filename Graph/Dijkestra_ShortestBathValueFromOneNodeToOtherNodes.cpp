
/**
- time complexity : o(n+m)*log n
- space complexity : o(n)

- this code is used to find shortest path from one node to other nodes
- weights are greater than zero
- Algorithm:-
1-Push in ds {cost,source}
2-initialize list  d
    d[i]=oo , i!=source
    d[i]=0  , i=source
3- curNode = node with minimum first value
4- if d[curNode] < value
    continue;
    else loop through neighbours , updating d[neighbour] and
        pushing in ds if we reached with better cost
- we will use priority queue

- complexity of adding a value in priority queue is log n


*/

#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int d[N],n,m;

vector<pair<int,int>>adj[N];
void dijkestra(int source)
{
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> >q;///sort form min to max
    q.push({0,source});
    for(int i=1;i<=n;i++)
    {
        d[i]=1e9;

    }
    d[source]=0;
    while(!q.empty())
    {
        int cost=q.top().first;
        int node=q.top().second;
        q.pop();
        if(d[node]<cost)
            continue;
        for(auto neg:adj[node])
        {
            int ncost=neg.second+cost;
            if(ncost<d[neg.first])
            {
                d[neg.first]=ncost;
                q.push({d[neg.first],neg.first});
            }

        }
    }


}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkestra(1);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<" ";
    return 0;
}
