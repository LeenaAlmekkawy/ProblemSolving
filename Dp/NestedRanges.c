#include <bits/stdc++.h>

using namespace std;
int n,l;
const int N=2000;
int fre[N];
int memo[N][N];
int rec(int be,int en)
{
    //cout<<s<<" "<<be<<" "<<en<<" "<<endl;

    if(memo[be][en]!=-1)
        return memo[be][en];
    if(be>=en)
    {
        return 0;
    }
    int c1=1e9;


    for(int i=be+1;i<en;i++)
    {
        if(fre[i]==1)
        {
        int d=rec(be,i)+rec(i,en)+(en-be);
        //cout<<d<<endl;
        c1=min(d,c1);
        }
    }
    if(c1==1e9)
        c1=0;
    memo[be][en]=c1;
    return c1;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   while(cin>>n)
   {if(n==0)
   break;

    fill(fre,fre+N,0);
    memset(memo,-1,sizeof memo);
    cin>>l;

    for(int i=0;i<l;i++)
    {
        int a;
        cin>>a;
        fre[a]++;
    }
    cout<<"The minimum cutting is "<<rec(0,n)<<"\n";


   }


    return 0;
}
