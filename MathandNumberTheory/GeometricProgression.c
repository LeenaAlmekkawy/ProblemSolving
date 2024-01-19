#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double calc_sum(ll a1, ll r, ll n)
{
    return (a1*( 1-pow(r,n) ))/(1-r);
}


double calc_an(ll a1,ll r, ll n)
{
   return (a1*pow(r,n-1));
}

/// an=a1 + (n-1)*d
int main()
{
   // cout<<fixed<<pow(2,33)<<endl;
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
     double a,r,n;
     cin>>a>>r>>n;
     cout<<"last number: "<<calc_an(a,r,n)<<endl;
     cout<<"sum of Geometric progression: "<<calc_sum(a,r,n)<<endl;

    return 0;
}
