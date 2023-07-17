#include <bits/stdc++.h>

using namespace std;
int n;
vector<int>vec;
int memo[50][50];

int rec(int ind,int pre,string s)
{
     cout<<s<<" "<<ind<<" "<<pre<<endl;
    if(ind==n)
    {
        return 0;
    }

    int c1=0;
    if(vec[ind]>pre)
       c1=rec(ind+1,vec[ind],s+"\t")+1;
    int c2=rec(ind+1,pre,s+"\t");

    return max(c1,c2);
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }
    cout<<rec(0,-1,"")<<endl;



    return 0;
}
