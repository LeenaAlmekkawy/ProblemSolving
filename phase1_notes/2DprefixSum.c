#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    ll arr[n+5][m+5];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>arr[i][j];
        }
    }
    ll pre[n+5][m+5];


    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            pre[i][j]=0;
        }
    }


    pre[1][1]=arr[1][1];


    for(int i=2; i<=n; i++)
    {
        pre[i][1]=pre[i-1][1]+arr[i][1];


    }
    for(int i=2; i<=m; i++)
    {
        pre[1][i]=pre[1][i-1]+arr[1][i];

    }




    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
        {
            pre[i][j]=pre[i-1][j]+pre[i][j-1]
                      -pre[i-1][j-1]+arr[i][j];
        }
    }

    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        long long ans=pre[c][d]-pre[c][b-1]-pre[a-1][d]+pre[a-1][b-1];
        cout<<ans<<endl;
    }
    return 0;
}