#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5;
const int oo=1e8;
vector<int>adj[N];
int dx[8]={-2,-2, 2, 2,-1,-1,1 , 1};
int dy[8]={ 1,-1, 1,-1, 2,-2, 2,-2};
int d[10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s,t;
    while(cin>>s>>t)
    {
        int srcx=s[0]-'a'+1;
        int srcy=s[1]-'0';
        int disx=t[0]-'a'+1;
        int disy=t[1]-'0';
        queue<pair<int,int>>q;
        q.push({srcx,srcy});
        bool vis[10][10]={0};
        pair<int,int> par[10][10]={};
        vis[srcx][srcy]=1;
        par[srcx][srcy]={-1,-1};

        d[srcx][srcy]=0;
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                d[i][j]=oo;
            }
        }
        d[srcx][srcy]=0;


        while(!q.empty())
        {
            int curx=q.front().first;
            int cury=q.front().second;

            q.pop();
            if(curx==disx&&cury==disy)
            {
                break;
            }
            for(int i=0;i<8;i++)
            {
                int nx=curx+dx[i];
                int ny=cury+dy[i];

                if(nx>=1&&nx<=8&&ny<=8&&ny>=1&&d[nx][ny]==oo)
                {   d[nx][ny]=d[curx][cury]+1;
                par[nx][ny]={curx,cury};
                    q.push({nx,ny});
                }
            }
        }
        pair<int,int>cur={disx,disy};
        vector<pair<int,int>>path;
        while(cur.first!=-1)
        {
            path.push_back(cur);
            cur=par[cur.first][cur.second];

        }
        reverse (path.begin(),path.end());
        for(auto cell:path)
        {
            cout<<cell.first<<" "<<cell.second<<endl;
        }
    //To get from e2 to e4 takes 2 knight moves.
        cout<<"To get from "<<s<<" to "<<t<<" takes "<<d[disx][disy]<<" knight moves."<<endl;

    }
}
