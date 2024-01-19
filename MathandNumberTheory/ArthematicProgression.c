#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll calc(ll a1,ll an, ll n)
{
   return ((a1+an)*n)/2;
}

/// an=a1 + (n-1)*d 
int main()
{
    ll n;
    cin>>n;
    cout<<calc(1,n,n);
    return 0;
}
