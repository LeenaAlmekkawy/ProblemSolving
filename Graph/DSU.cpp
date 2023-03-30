#include <bits/stdc++.h>

/************************************
DSU:log n
----------------------------------
1- choose parent for each component
2- update parent of node when needed
3- join two components, i will join parents
4- update parent smaller component with parent bigger component

----------------------------------
we need two arrays
par[N],sz[N]

int find(int node )
{
   if(node ==par[node])
    {
  return node;
    }

else
   {

    return par[node]=find(node);
   }
}

*************************************/
using namespace std;
const int N=1e5+5;
int component;
int par[N], sz[N];
int fnd(int node)
{
    if(par[node]==node)
    {
        return node;
    }
    else
    {
        return par[node]=fnd(par[node]);
    }
}
void join(int u,int v)
{
    u=fnd(u);
    v=fnd(v);
    if(u==v)
        return ;
    if(sz[v]>sz[u])
        swap(v,u);

    par[v]=u;
    sz[u]+=sz[v];
    component--;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   int n;
   cin>>n;

    component=n;
    fill(sz+1,sz+n+1,1);
    iota(par,par+n+1,0);

    
    return 0;
}
