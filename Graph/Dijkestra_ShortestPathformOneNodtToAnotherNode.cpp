
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
typedef long long ll;
const int N=1e5+5;
vector<pair<int,int>>adj[N];
int n,m;


void dijkestra(int source,int dis)
{   ll d[n+1];
int par[n+1];


    priority_queue<pair<ll,int> >q;///sort form min to max
    q.push({0,source});
    for(int i=1;i<=n;i++)
    {
        d[i]=1e12;

    }
    d[source]=0;
    par[source]=-1;
    while(!q.empty())
    {
        ll cost=-1*q.top().first;
        int node=q.top().second;
        q.pop();
        if(d[node]<cost)
            continue;
        if(node==dis)
            break;

        for(auto neg:adj[node])
        {
            int ncost=neg.second+cost;
            if(ncost<d[neg.first])
            {
                d[neg.first]=ncost;
                q.push({-1*d[neg.first],neg.first});
                par[neg.first]=node;
            }

        }
    }
    if(d[dis]==1e12)
        cout<<"-1\n";
    else
    {
        int cur=dis;
        vector<int>path;
        while(cur!=-1)
        {
            path.push_back(cur);
            cur=par[cur];
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++)
        {
            if(i!=path.size()-1)
                cout<<path[i]<<" ";
            else
                cout<<path[i]<<"\n";

        }

    }


}
int main()
{ ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkestra(1,n);



    return 0;
}