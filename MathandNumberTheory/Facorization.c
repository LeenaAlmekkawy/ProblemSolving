#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<int>vec;
    for(int i=2;i*i<=n;i++)//sqrt function take a higher time
    {
        if(n%i==0)
        {
            
            vec.push_back(i);
            if(i*i!=n)
            {
                
                vec.push_back(n/i);
            }
            
        }
    }
    return 0;
}
