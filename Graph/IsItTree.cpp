#include <bits/stdc++.h>
/*
->Acyclic and 1 component
or
->m==n-1  and 1 component
*/
using namespace std;
const int N=1e5;
bool vis[N];
vector<int>adj[N];

void dfs(int node,int par)
{
    vis[node]=1;
    for(int neg:adj[node])
    {
        if(neg==par)
        {
            continue;
        }
        if(vis[neg])
        {
            cout<<"NO"<<endl;
            exit(0);//terminate the program without return to main function
        }
        dfs(neg,node);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            return cout<<"NO",0;
        }
    }
    (m==n-1)?cout<<"YES":cout<<"NO";


    return 0;
}
