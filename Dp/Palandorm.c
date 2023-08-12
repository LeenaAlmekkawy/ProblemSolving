#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll memo[1005][1005];
bool ok=0;
vector<int>vec;


ll rec(int i,int j)
{


    if(i==j)
    {
        return 1;
    }
   if(i+1==j)
    {
        return 2+(s[i]==s[j]);
    }

    if(memo[i][j]!=-1)
          return memo[i][j];


    ll c1=0;

    if(s[i]==s[j])
    {  c1=rec(i+1,j-1)+1;
    }
    ll c2=rec(i+1,j);
    ll c3=rec(i,j-1);


    memo[i][j]=c1+c2+c3-rec(i+1,j-1);
    return memo[i][j];


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {

        memset(memo,-1,sizeof memo);
        cin>>s;
        cout<<rec(0,(s.size()-1))<<"\n";

    }
    return 0;
}
