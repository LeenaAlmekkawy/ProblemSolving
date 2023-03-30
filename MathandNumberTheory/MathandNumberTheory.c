#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll add(ll a,ll b,ll m);

ll mul(ll a,ll b,ll m);

ll sub(ll a,ll b,ll m);

ll FastPower(ll x,ll n,ll m);
int main()
{

     return 0;
}

ll add(ll a,ll b,ll m)
{
    return ((a%m)+(b%m))%m;
}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
ll sub(ll a,ll b,ll m)
{
    return ((a%m)-(b%m)+m)%m;
}

ll FastPower(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}