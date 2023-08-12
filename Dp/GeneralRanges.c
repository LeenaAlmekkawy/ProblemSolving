#include <bits/stdc++.h>
using namespace std;

string s;

int memo[1005][1005];
bool ok=0;
vector<int>vec;

int rec(int i,int j)
{

    if(i>=j)
    {return 0;
    }
    if(memo[i][j]!=-1)
        return memo[i][j];




   int c1=rec(i+1,j)+1;
   int c2=rec(i,j-1)+1;
   int c3=1e9;
   int add=1;
   if(s[i]==s[j])
    add=0;
   c3=rec(i+1,j-1)+add;//replace


memo[i][j]=min(c1,min(c2,c3));
    return memo[i][j];


}
int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    { cnt++;
         memset(memo,-1,sizeof memo);
        cin>>s;
        cout<<"Case "<<cnt<<": "<<rec(0,s.size()-1)<<"\n";

    }
    return 0;
}
