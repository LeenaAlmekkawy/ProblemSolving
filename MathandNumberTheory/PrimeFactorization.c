#include<bits/stdc++.h>

int main()
{
    //myf.open("file.txt");
    //freopen("task.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for (int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            v.push_back(i);
        }
    }
    if (n!=1)
    {
        v.push_back(n);
    }
    for (int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}