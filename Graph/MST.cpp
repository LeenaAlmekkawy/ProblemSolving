#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/**

-(MST)minimum spanning tree: is a subset of the edges of a connected,
edge-weighted undirected graph that connects all the vertices together,
without any cycles and with the minimum possible total edge weight.
That is, it is a spanning tree whose sum of edge weights is as small as possible.

- We will use greedy algorithm

- we can iterate on edges sorted by weight and ask a question if adding is necessary then add it
other wise do not add it.

- if there is an edge that is should be in the MST, i should add it imediately when i enter kruskal function

- MST doesnot achieve minimum path

///problem link: https://vjudge.net/contest/547199#problem/C

***/

const int N=1e6;
ll sz[N],par[N];
ll component=N;
int fnd(int node)
{
    if(node==par[node])
        return node;
    else
    {
        return par[node]=fnd(par[node]);
    }

}
bool join(int u,int v)
{
    u=fnd(u);
    v=fnd(v);
    if(u==v)
        return 0;

    if(sz[u]<sz[v])
    {
        swap(u,v);
    }

    par[v]=u;
    sz[u]+=sz[v];
    ///if needed
    component--;
    return 1;

}
struct edge
{
    int u,v,w;
};

bool cmp(edge x,edge y )
{
    return x.w < y.w;
    /**
    if weight of x is less than weight of y then return true
      else then return false

    */
}

int kruskal(vector<edge>edges)
{
    sort(edges.begin(),edges.end(),cmp);
    ll total=0;
    for(auto i:edges)
    {
        if(join(i.u, i.v))
        {
            total+=i.w;
            ///if you want to save the MST just add vector here
        }
    }
    return total;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {   vector<edge>v;
        int n;
        cin>>n;

        fill(sz,sz+n+5,1);
        iota(par,par+n+5,0);

        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            ll k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int u,c;
                cin>>u>>c;
                v.push_back({i,u,c});

            }

        }

        cout<<kruskal(v)<<"\n";
    }


    return 0;
}
