#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,par[N];
bool vis[N];
vector<int>adj[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    vis[1]=1;
    par[1]=1;
    bool tree=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int neg:adj[cur])
        {
            if(!vis[neg])
            {
                q.push(neg);
                par[neg]=cur;
                vis[neg]=1;
            }
            else if(neg!=par[cur])
            {
                tree=0;
            }

        }
    }
    //cout<<tree<<endl;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            tree=0;

    }
    if(m==n-1&&tree)
    {
        tree=1;
    }
    else
    {
        tree=0;
    }
    (tree==1)?printf("YES"):printf("NO");
    return 0;
}
